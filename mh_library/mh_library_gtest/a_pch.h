//
// pch.h
// Header for standard system include files.
// なぜa_pch.hという名前になっているかというと
// プリコンパイルヘッダは必ず最初にincludeされなければいけませんが、
// VSCodeのコード整形を使用した際にinclude順番が入れ替えられる事象があり、
// pch.hだと後ろに整形されるパターンが存在するのでa_pch.hとしている
//

#pragma once

#include "gtest/gtest.h"
