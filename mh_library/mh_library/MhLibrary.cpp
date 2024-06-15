#include <memory>
#include <mhl/output/console/IConsoleOutputables.hpp>
#include <mhl/output/console/OutputConsole.hpp>
#include <mhl/output/console/OutputConsoleVsSjis.hpp>
#include <mhl/output/console/OutputConsoles.hpp>
#include <mhl/system/singleton/SingletonCleanup.hpp>
#include <mhl/test_code/TestMhl.hpp>
#include <mhl/test_program/TestMhlTestProgram.hpp>

int main()
{
    std::shared_ptr<mhl::output::console::IConsoleOutputables> output(
        new mhl::output::console::OutputConsoles());
    std::shared_ptr<mhl::output::console::IConsoleOutputable> output_console(
        new mhl::output::console::OutputConsole);
    std::shared_ptr<mhl::output::console::IConsoleOutputable> output_vs(
        new mhl::output::console::OutputConsoleVsSjis);
    output->Add(output_console);
    output->Add(output_vs);

    test_code::TestMhl test(output);
    test.ExecuteUnitTest();

    test_program::TestMhlTestProgram testProgram(output);
    testProgram.ExecuteUnitTest();

    output->PrintLine(
        "--- main test -------------------------------------------------------");

    // シングルトン終了処理
    mhl::system::singleton::SingletonCleanup::Execute();
    mhl::system::singleton::SingletonCleanup::Finalize();
}
