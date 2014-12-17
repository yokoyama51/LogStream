

/**
 * @brief	CLogFileStreamクラス宣言ファイル
 */

#ifndef __YOKOYAMA51_LOGFILEWRITER_H__
#define __YOKOYAMA51_LOGFILEWRITER_H__

#include "logstream.h"

#include <string>
#include <fstream>
#include <boost/function.hpp>


/**
 * @brief	ログファイル出力
 *
 * @note	m_directory以下に年別フォルダを作成し日付ごとにログファイルを作成する<br>
 *			m_directory<br>
 *				| - 2014<br>
 *				|	| - prefix_2014mmdd.log<br>
 *				|	| - prefix_yyyymmdd.log<br>
 *				| - 2015<br>
 *				|	| - prefix_2015mmdd.log<br>
 *				|	| - prefix_yyyymmdd.log<br>
 */
class CLogFileStream : public CLogStream
{
public: // 構築/破棄
	CLogFileStream();
	CLogFileStream(const char * directory, const char * prefix);
	virtual ~CLogFileStream();

public:
	virtual void WriteInfomation(const char * msg);
	virtual void WriteMessge(const char * msg);
	virtual void WriteWarning(const char * msg);
	virtual void WriteError(const char * msg);
	virtual void WriteException(const std::exception &ex);
	virtual void WriteDebug(const char * msg);

private:
	void SetDirectoryAndPrefix(const char * directory, const char * appname);
	void GetFilePath(std::string &out);
	void Write(boost::function<void (std::ofstream&)> &write_func);

private:
	std::string m_directory; ///< 出力ディレクトリ
	std::string m_prefix;	 ///< ログファイルプレフィクス
}; /* CLogFileStream */

#endif /* __YOKOYAMA51_LOGFILEWRITER_H__ */
