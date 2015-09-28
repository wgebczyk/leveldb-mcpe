#include "leveldb/brotli_compressor.h"

#include <brotli/dec/decode.h>
#include <brotli/enc/encode.h>
#include <brotli/enc/streams.h>

namespace leveldb {

	void BrotliCompressor::compressImpl(const char* input, size_t length, ::std::string& buffer) const {
		brotli::BrotliParams params;
		params.quality = compressionLevel;

		buffer.reserve(length / 10);

		brotli::BrotliMemIn in(input, length);
		assert(buffer.empty());
		brotli::BrotliStringOut out(&buffer, INT_MAX);

		BrotliCompress(params, &in, &out);
	}

	static int stringAppend(void* self, const uint8_t* buf, size_t len) {
		((std::string*)self)->append((char*)buf, len);
		return len;
	}

	bool BrotliCompressor::decompress(const char* input, size_t length, ::std::string &output) const {

		BrotliMemInput in;
		in.buffer = (uint8_t*)input;
		in.length = length;
		in.pos = 0;
		BrotliInput inStream;
		inStream.cb_ = BrotliMemInputFunction;
		inStream.data_ = &in;

		BrotliOutput out;
		out.cb_ = stringAppend;
		out.data_ = &output;

		//brotli compresses to less than 10% of the original size on average, so reserve a whole lot of memory
		output.reserve(length * 20); 

		return BrotliDecompress(inStream,out) == 1;
	}
}
