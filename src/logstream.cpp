

/**
 * @brief	CLogStreamクラス定義ファイル
 */

#include "logstream.h"

#include <map>
#include <string>
#include <boost/assign.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;


/**
 * @brief	コンストラクタ
 */
CLogStream::CLogStream()
{
}


/**
 * @brief	デストラクタ
 */
CLogStream::~CLogStream()
{
}


/**
 * @brief	ストリームへの出力
 *
 * @param	type	出力種別
 * @param	stream	出力するストリームオブジェクト
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogStream::_Write(LogType type, std::ostream &stream, const char * msg)
{
	// 時刻取得
	boost::posix_time::ptime now_(boost::posix_time::microsec_clock::local_time());

	// 時刻出力フォーマット設定
	boost::posix_time::time_facet * f = new boost::posix_time::time_facet("%Y/%m/%d %H:%M:%S.%f");
	std::stringstream ss;
	ss.imbue(std::locale(ss.getloc(), f));
	//delete f; time_facetの解放はlocaleオブジェクトが実施するので、明示的なdeleteは不要

	using namespace boost::assign; 
	static map<LogType, string> _map = map_list_of(LOG_INFOMATION, "INFO")(LOG_MESSAGE, "MESSAGE")(LOG_ERROR, "ERROR")(LOG_WARNING, "WARNING")(LOG_EXCEPTION, "EXCEPTION")(LOG_DEBUG, "DEBUG");
	map<LogType, string>::iterator it = _map.find(type);
	assert(it != _map.end()); // 必ずヒットするはず

	ss << now_ << " [" << (*it).second << "] " << msg << "\n";
	const string &s = ss.str();
	stream.write(s.c_str(), s.length()); // 出力
}


/**
 * @brief	インフォメーション出力
 *
 * @param	stream	出力するストリームオブジェクト
 * @param	msg		出力文字列
 */
void CLogStream::_WriteInfomation(std::ostream &stream, const char * msg)
{
	_Write(LOG_INFOMATION, stream, msg);
}


/**
 * @brief	メッセージ出力
 *
 * @param	stream	出力するストリームオブジェクト
 * @param	msg		出力文字列
 */
void CLogStream::_WriteMessge(std::ostream &stream, const char * msg)
{
	_Write(LOG_MESSAGE, stream, msg);
}


/**
 * @brief	警告出力
 *
 * @param	stream	出力するストリームオブジェクト
 * @param	msg		出力文字列
 */
void CLogStream::_WriteWarning(std::ostream &stream, const char * msg)
{
	_Write(LOG_WARNING, stream, msg);
}


/**
 * @brief	エラー出力
 *
 * @param	stream	出力するストリームオブジェクト
 * @param	msg		出力文字列
 */
void CLogStream::_WriteError(std::ostream &stream, const char * msg)
{
	_Write(LOG_ERROR, stream, msg);
}


/**
 * @brief	例外情報出力
 *
 * @param	stream	出力するストリームオブジェクト
 * @param	ex		例外オブジェクト
 */
void CLogStream::_WriteException(std::ostream &stream, const std::exception &ex)
{
	_Write(LOG_EXCEPTION, stream, ex.what());
}


/**
 * @brief	デバッグ情報出力
 *
 * @param	stream	出力するストリームオブジェクト
 * @param	msg		出力文字列
 *
 * @note	本関数はデバッグモード時のみ実行される
 */
void CLogStream::_WriteDebug(std::ostream &stream, const char * msg)
{
#ifndef NDEBUG
	_Write(LOG_DEBUG, stream, msg);
#endif /* NDEBUG */
}