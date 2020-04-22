#include "mh_library/util/output/IOutputConsole.hpp"
#include "mh_library/util/output/OutputConsole.hpp"

int main() {
    mh_library::IOutputConsole* console = new mh_library::OutputConsole();
    console->Print("HelloWorld");
    if (console) {
        delete console;
        console = NULL;
    }
    return 0;
}
