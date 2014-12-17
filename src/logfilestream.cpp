


/**
 * @brief	CLogFileStreamクラス定義ファイル
 */

#include "logfilestream.h"

#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;


/**
 * @brief	コンストラクタ
 */
CLogFileStream::CLogFileStream()
{
	SetDirectoryAndPrefix("./log", "app");
}


/**
 * @brief	コンストラクタ
 *
 * @param	directory	出力ディレクトリ
 * @param	prefix		ログファイルプレフィクス文字
 */
CLogFileStream::CLogFileStream(const char * directory, const char * prefix)
{
	SetDirectoryAndPrefix(directory, prefix);
}


/**
 * @brief	デストラクタ
 */
CLogFileStream::~CLogFileStream()
{
}


/**
 * @brief	出力ディレクトリと出力ファイルプレフィクス文字の設定
 *
 * @param	directory	出力ディレクトリ
 * @param	prefix		ログファイルプレフィクス文字
 */
void CLogFileStream::SetDirectoryAndPrefix(const char * directory, const char * prefix)
{
	boost::filesystem::path path(directory);
	boost::filesystem::path abs = boost::filesystem::absolute(path);

	m_directory = abs.string();
	m_prefix = prefix;
}


/**
 * @brief	出力ファイルパス取得
 *
 * @param[out]	out		ファイルパスを格納するバッファ
 */
void CLogFileStream::GetFilePath(std::string &out)
{
	// 時刻取得
	boost::posix_time::ptime now_(boost::posix_time::second_clock::local_time());

	// 出力ディレクトリ
	boost::filesystem::path p(m_directory);
	p = p / to_string((long long)now_.date().year()) / "";
	string dir = p.string();
	
	if(!boost::filesystem::exists(dir)){
		boost::filesystem::create_directories(dir);
	}

	boost::filesystem::path sep_("/");
	string sep = sep_.make_preferred().string();

	stringstream ss2;
	ss2 << dir << sep 
		<< m_prefix << "_" 
		<< now_.date().year() 
		<< setfill('0') << setw(2) << now_.date().month().as_number() 
		<< setfill('0') << setw(2) << now_.date().day()
		<< ".log";
	
	out = ss2.str();
}


/**
 * @brief	出力関数を呼び出し、ファイルに出力する
 *
 * @param	write_func	出力関数オブジェクト
 */
void CLogFileStream::Write(boost::function<void (std::ofstream&)> &write_func)
{
	string path;
	GetFilePath(path);

	ofstream stream(path.c_str(), ios::out|ios::app); // ログファイルは追記方式
	if(stream.is_open()){
		write_func(stream);
	}
}


/**
 * @brief	インフォメーション出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogFileStream::WriteInfomation(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteInfomation, _1, msg);
	Write(f);
}


/**
 * @brief	メッセージ出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogFileStream::WriteMessge(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteMessge, _1, msg);
	Write(f);
}


/**
 * @brief	警告出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogFileStream::WriteWarning(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteWarning, _1, msg);
	Write(f);
}


/**
 * @brief	エラー出力
 *
 * @param	msg		出力文字列
 *
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogFileStream::WriteError(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteError, _1, msg);
	Write(f);
}


/**
 * @brief	例外出力
 *
 * @param	ex		例外オブジェクト
 */
void CLogFileStream::WriteException(const std::exception &ex)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteException, _1, ex);
	Write(f);
}


/**
 * @brief	デバッグ情報出力
 *
 * @param	msg		出力文字列
 *
 * @note	本関数はデバッグモード時のみ実行される
 * @warning	msg内の改行コードは特に判定しない。そのため、改行コードが含まれる場合はフォーマットが崩れる
 */
void CLogFileStream::WriteDebug(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteDebug, _1, msg);
	Write(f);
}



