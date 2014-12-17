

/**
 * @brief	CLogConsoleWriterクラス宣言ファイル
 */

#ifndef __YOKOYAMA51_LOGCONSOLEWRITER_H__
#define __YOKOYAMA51_LOGCONSOLEWRITER_H__


#include "logstream.h"


/**
 * @brief	ログ出力オブジェクト
 */
class CLogConsoleWriter : public CLogStream
{
public: // 構築/破棄
	CLogConsoleWriter();
	~CLogConsoleWriter();

public:
	virtual void WriteInfomation(const char * msg);
	virtual void WriteMessge(const char * msg);
	virtual void WriteWarning(const char * msg);
	virtual void WriteError(const char * msg);
	virtual void WriteException(const std::exception &ex);
	virtual void WriteDebug(const char * msg);
}; /* CLogConsoleWriter */

#endif /* __YOKOYAMA51_LOGCONSOLEWRITER_H__ */
