#ifndef MHL_SYSTEM_VARIABLE_LENGTH_ARGUMENTS_GET_VARIABLE_LENGTH_ARGUMENTS_HPP_
#define MHL_SYSTEM_VARIABLE_LENGTH_ARGUMENTS_GET_VARIABLE_LENGTH_ARGUMENTS_HPP_

#include <vector>

namespace mhl {
namespace system {
namespace variable_length_arguments {

class GetVariableLengthArguments {
 public:
  /**
   * @brief 可変引数を取得
   *
   * @param arg_string 取得した可変引数文字列
   * @param format フォーマット(書式指定文字列)
   * @param args 書式設定する省略可能な引数
   */
  template <typename... Args>
  void ToString(std::string& arg_string, const char* format, Args... args) {
    size_t len = std::snprintf(nullptr, 0, format, args...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, format, args...);
    arg_string = std::string(&buf[0], &buf[0] + len);
  }

  /**
   * @brief 可変引数を取得
   *
   * @param arg_char 取得した可変引数文字列
   * @param buffer_count arg_charの文字数
   * @param format フォーマット(書式指定文字列)
   * @param args 書式設定する省略可能な引数
   */
  template <typename... Args>
  void ToChar(char arg_char[], size_t buffer_count, const char* format,
              Args... args) {
    size_t len = std::snprintf(nullptr, 0, format, args...);
    std::vector<char> buf(len + 1);
    std::snprintf(arg_char, buffer_count - 1, format, args...);
  }
};

#if 0
/**
 * @brief メルセンヌ・ツイスタ乱数
 *
 */
class MtRand : public mhl::IRandGetable {
 public:
  /**
   * @brief コンストラクタ
   *
   */
  MtRand();

  /**
   * @brief デストラクタ
   *
   */
  virtual ~MtRand();

  /**
   * @brief 乱数の種を設定する
   *
   * @param seed 設定する乱数
   */
  void setSeed(uint64_t seed) override;

  /**
   * @brief 乱数の種を設定する
   *
   * @param seed 設定する乱数
   */
  void setSeed(uint32_t seed) override;

  /**
   * @brief 現在時刻から乱数を設定する
   *
   */
  void setTimeSeed() override;

  /**
   * @brief 乱数を取得する
   *
   * @return int32_t 生成された乱数
   */
  int32_t getRandInt32(int32_t min, int32_t max) const override;

  /**
   * @brief 乱数を取得する
   *
   * @param min 最小値
   * @param max 最大値
   * @return uint32_t 生成された乱数
   */
  uint32_t getRandUint32(uint32_t min, uint32_t max) const override;

 private:
  std::shared_ptr<std::mt19937_64> mt_;
};
#endif
}  // namespace variable_length_arguments
}  // namespace system
}  // namespace mhl

#endif  // MHL_SYSTEM_VARIABLE_LENGTH_ARGUMENTS_GET_VARIABLE_LENGTH_ARGUMENTS_HPP_
