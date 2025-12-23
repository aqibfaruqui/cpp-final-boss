#include <string>
#include <fstream>

class FileGuard {
    private:
        FILE* handle;

    public:
        FileGuard(const std::string& filename, const char* mode = "w") {
            handle = fopen(filename.c_str(), mode);
            if (!handle) throw std::runtime_error("Failed to open file");
        }

        /* 
         * Rule of 3
         *
         * Marked delete to prevent:
         *  FileGuard f1("example.txt");
         *  FileGuard f2(f1);
         * 
         * Otherwise if f1 goes out of scope, f2 will
         * fclose() the same file i.e. double-close
         */
        FileGuard(const FileGuard&) = delete;
        FileGuard& operator=(const FileGuard&) = delete;

        /* 
         * Rule of 5
         *
         * Move support
         */
        FileGuard(FileGuard&& other) noexcept : handle(other.handle) {
            other.handle = nullptr;
        }

        FileGuard& operator=(FileGuard&& other) noexcept {
            if (this != &other) {
                if (handle) fclose(handle);
                handle = other.handle;
                other.handle = nullptr;
            }
            return *this;
        }

        ~FileGuard() {
            if (handle) fclose(handle);
        }

        FILE* get() const {
            return handle;
        }
};

/*
* RAII in use
*
* fclose() in destructor closes file when 
* try-block goes out of scope
* 
* We'd leak resources without RAII:
*  FILE* f = fopen("output.txt", "w");
*  fprintf(f, "Hello RAII!\n");
*  throw std::runtime_error("Boom!");  // <-- never reaches fclose
*  fclose(f);
*/
int main() {
    try {
        FileGuard fg("example.txt", "w");
        fprintf(fg.get(), "Hellooo RAII!\n");
        throw std::runtime_error("Something went wrong");   // <-- file still closes!
    } catch (...) {
        // Nothing needed, file already closed :D
    }
    return 0;
}