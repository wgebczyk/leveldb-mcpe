#if MCPE_CONNECTEDSTORAGE_ENABLED

#include "leveldb/env.h"

namespace leveldb {
	namespace {

		class CSEnv : public Env {
			virtual Status NewSequentialFile(const std::string& fname, SequentialFile** result) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status NewRandomAccessFile(const std::string& fname, RandomAccessFile** result) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status NewWritableFile(const std::string& fname, WritableFile** result) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual bool FileExists(const std::string& fname) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status GetChildren(const std::string& dir, std::vector<std::string>* result) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status DeleteFile(const std::string& fname) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status CreateDir(const std::string& dirname) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status DeleteDir(const std::string& dirname) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status GetFileSize(const std::string& fname, uint64_t* file_size) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status RenameFile(const std::string& src, const std::string& target) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status LockFile(const std::string& fname, FileLock** lock) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status UnlockFile(FileLock* lock) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual void Schedule(void(*function) (void* arg), void* arg) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual void StartThread(void(*function) (void* arg), void* arg) override {
				throw std::logic_error("The method or operation is not implemented.");
}

			virtual Status GetTestDirectory(std::string* path) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual Status NewLogger(const std::string& fname, Logger** result) override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual uint64_t NowMicros() override {
				throw std::logic_error("The method or operation is not implemented.");
			}

			virtual void SleepForMicroseconds(int micros) override {
				throw std::logic_error("The method or operation is not implemented.");
			}


		}

		static CSEnv* default_env;
		Env* Env::Default() {
			if (default_env == nullptr) {
				default_env = new CSEnv();
			}

			return default_env;
		}
	}
}

























#endif