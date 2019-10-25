#ifndef NO_ZLIB

#include "leveldb/zlib_compressor.h"

#include <zlib.h>
#include <algorithm>

#include <iostream>

namespace leveldb {

	void ZlibCompressorBase::compressImpl(const char* input, size_t length, ::std::string& buffer) const
	{
		std::cout << "entering ZlibCompressorBase::compressImpl" << std::endl;
		const size_t BUFSIZE = 128 * 1024;
		unsigned char temp_buffer[BUFSIZE];

		//reserve enough memory to not reallocate on the fly
		buffer.reserve(buffer.size() + compressBound(length));

		z_stream strm;
		strm.zalloc = 0;
		strm.zfree = 0;
		strm.next_in = (unsigned char *)(input);
		strm.avail_in = (uint32_t)length;
		strm.next_out = temp_buffer;
		strm.avail_out = BUFSIZE;

		auto res = deflateInit2(&strm, compressionLevel, Z_DEFLATED, _window(), 8, Z_DEFAULT_STRATEGY);
		assert(res == Z_OK);
		
		int deflate_res = Z_OK;
		while (strm.avail_in != 0)
		{
			int res = deflate(&strm, Z_NO_FLUSH);
			assert(res == Z_OK);
			if (strm.avail_out == 0)
			{
				buffer.append(temp_buffer, temp_buffer + BUFSIZE);
				strm.next_out = temp_buffer;
				strm.avail_out = BUFSIZE;
			}
		}

		while (deflate_res == Z_OK)
		{
			if (strm.avail_out == 0)
			{
				buffer.append(temp_buffer, temp_buffer + BUFSIZE);
				strm.next_out = temp_buffer;
				strm.avail_out = BUFSIZE;
			}
			deflate_res = deflate(&strm, Z_FINISH);
		}

		assert(deflate_res == Z_STREAM_END);
		buffer.append(temp_buffer, temp_buffer + BUFSIZE - strm.avail_out);
		deflateEnd(&strm);
		std::cout << "exiting ZlibCompressorBase::compressImpl" << std::endl;
	}

	int ZlibCompressorBase::inflate(const char* input, size_t length, ::std::string &output) const {
		std::cout << "entering ZlibCompressorBase::inflate" << std::endl;
		const int CHUNK = 64 * 1024;

		int ret;
		size_t have;
		z_stream strm;
		unsigned char out[CHUNK];

		/* allocate inflate state */
		strm.zalloc = Z_NULL;
		strm.zfree = Z_NULL;
		strm.opaque = Z_NULL;
		strm.avail_in = (uint32_t)length;
		strm.next_in = (Bytef*)input;

		ret = inflateInit2(&strm, _window());

		if (ret != Z_OK)
		{
			std::cout << "exiting ZlibCompressorBase::inflate (inflateInit2 failed) with errorcode: " << ret << std::endl;
			if (ret == Z_MEM_ERROR) {
				std::cout << "(Error with memory allocation)" << std::endl;
			}
			return ret;
		}

		/* decompress until deflate stream ends or end of file */
		do {
			/* run inflate() on input until output buffer not full */
			do {

				strm.avail_out = CHUNK;
				strm.next_out = out;

				ret = ::inflate(&strm, Z_NO_FLUSH);

				if (ret == Z_NEED_DICT || ret < 0) {
					std::cout << "detected error in inflate: errorcode:" << ret << std::endl;
				}

				if (ret == Z_NEED_DICT) {
					ret = Z_DATA_ERROR;
				}
				if (ret < 0) {
					(void)inflateEnd(&strm);
					std::cout << "exiting ZlibCompressorBase::inflate with errorcode: " << ret << std::endl;
					return ret;
				}

				have = CHUNK - strm.avail_out;

				output.append((char*)out, have);

			} while (strm.avail_out == 0);

			/* done when inflate() says it's done */
		} while (ret != Z_STREAM_END);

		/* clean up and return */
		(void)inflateEnd(&strm);
		if (ret != Z_STREAM_END) {
			printf("Found unexpected return result\n");
		}

		std::cout << "preparing to exit ZlibCompressorBase - wrote " << output.size() << " bytes into output buffer" << std::endl;

		std::cout << "exiting ZlibCompressorBase::inflate" << std::endl;
		return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
	}

	bool ZlibCompressorBase::decompress(const char* input, size_t length, ::std::string &output) const {
		return inflate(input, length, output) == Z_OK;
	}
		
	int ZlibCompressorBase::_window() const {
		return raw ? -15 : 15;
	}

}

#endif