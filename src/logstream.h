

/**
 * @brief	CLogStreamクラス宣言ファイル
 */

#ifndef __YOKOYAMA51_LOGSTREAM_H__
#define __YOKOYAMA51_LOGSTREAM_H__


#include "logstreaminterface.h"

#include <ostream>


/**
 * @brief	ログ出力オブジェクト
 */
class CLogStream : public CLogStreamInterface
{
public: // 構築/破棄
	CLogStream();
	virtual ~CLogStream();

protected:
	static void _WriteInfomation(std::ostream &stream, const char * msg);
	static void _WriteMessge(std::ostream &stream, const char * msg);
	static void _WriteWarning(std::ostream &stream, const char * msg);
	static void _WriteError(std::ostream &stream, const char * msg);
	static void _WriteException(std::ostream &stream, const std::exception &ex);
	static void _WriteDebug(std::ostream &stream, const char * msg);

private:
	/* @brief ログ出力種別 */
	enum LogType { LOG_INFOMATION=0, ///< 情報
				   LOG_MESSAGE,		 ///< メッセージ
				   LOG_ERROR,		 ///< エラー
				   LOG_WARNING,		 ///< 警告
				   LOG_EXCEPTION,	 ///< 例外
				   LOG_DEBUG };		 ///< デバッグ時出力

	static void _Write(LogType type, std::ostream &stream, const char * msg);

}; /* CLogStream */

#endif /* __YOKOYAMA51_LOGSTREAM_H__ */
