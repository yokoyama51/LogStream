

/**
 * @brief	CLogConsoleWriterクラス定義ファイル
 */

#include "logconsolestream.h"

#include <iostream>

using namespace std;


/**
 * @brief	コンストラクタ
 */
CLogConsoleWriter::CLogConsoleWriter()
{
}


/**
 * @brief	デストラクタ
 */
CLogConsoleWriter::~CLogConsoleWriter()
{
}


/**
 * @brief	インフォメーション出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogConsoleWriter::WriteInfomation(const char * msg)
{
	CLogStream::_WriteInfomation(std::cout, msg);
}


/**
 * @brief	メッセージ出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogConsoleWriter::WriteMessge(const char * msg)
{
	CLogStream::_WriteMessge(std::cout, msg);
}


/**
 * @brief	警告出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogConsoleWriter::WriteWarning(const char * msg)
{
	CLogStream::_WriteWarning(std::cout, msg);
}


/**
 * @brief	エラー出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogConsoleWriter::WriteError(const char * msg)
{
	CLogStream::_WriteError(std::cout, msg);
}


/**
 * @brief	例外出力
 *
 * @param	ex		例外オブジェクト
 */
void CLogConsoleWriter::WriteException(const std::exception &ex)
{
	CLogStream::_WriteException(std::cout, ex);
}


/**
 * @brief	デバッグ情報出力
 *
 * @param	msg		出力文字列
 *
 * @note	本関数はデバッグモード時のみ実行される
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogConsoleWriter::WriteDebug(const char * msg)
{
	CLogStream::_WriteDebug(std::cout, msg);
}



