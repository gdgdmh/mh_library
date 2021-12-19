#include <memory>
#include <mhl/output/console/iconsole_outputables.hpp>
#include <mhl/output/console/output_console.hpp>
#include <mhl/output/console/output_console_vs_sjis.hpp>
#include <mhl/output/console/output_consoles.hpp>
#include <mhl/test_code/test_mhl.hpp>
#include <mhl/test_program/test_mhl_test_program.hpp>

int main() {
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
  output->Clear();
  return 0;
}

// mh_library_exec.cpp : このファイルには 'main'
// 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

/*
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
*/

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント:
//    1. ソリューション エクスプローラー
//    ウィンドウを使用してファイルを追加/管理します
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード
//   ファイルを作成するか、[プロジェクト] > [既存の項目の追加]
//   と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] >
//   [プロジェクト] と移動して .sln ファイルを選択します
