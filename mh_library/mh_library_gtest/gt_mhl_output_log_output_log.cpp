
#include "a_pch.h"
#include <mhl/output/log/output_log.hpp>
#include <mhl/system/file/file_deleter.hpp>

namespace mhl {
namespace output {
namespace log {

TEST(OutputLog, Constructor) {}

/**
 * @brief test
 *
 */
TEST(OutputLog, Initialize) {
  //const std::string file_name = "gtest_output_log_initialize.txt";
  // Arrange
  //mhl::system::file::FileDeleter fd;
  //fd.Delete(file_name);

  // Act
  // Assert
  // EXPECT_EQ(fd.Delete(path), true);
}

TEST(OutputLog, Finalize) {}

TEST(OutputLog, Print) {}

TEST(OutputLog, PrintLine) {}

TEST(OutputLog, IsInitialize) {}

}  // namespace log
}  // namespace output
}  // namespace mhl
