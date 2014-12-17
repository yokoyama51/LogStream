

/**
 * @brief	CLogStreamInterfaceクラス宣言ファイル
 */

#ifndef __YOKOYAMA51_LOGSTREAM_INTERFACE_H__
#define __YOKOYAMA51_LOGSTREAM_INTERFACE_H__

#include <exception>


/**
 * @brief	ログ出力インターフェース
 */
class CLogStreamInterface
{
public: 
	virtual ~CLogStreamInterface() {}

public: // 純粋仮想関数/インターフェース定義
	/**
	 * @brief	インフォメーション出力
	 * @param	stream	出力するストリームオブジェクト
	 * @param	msg		出力文字列
	 */
	virtual void WriteInfomation(const char * msg) = 0;

	/**
	 * @brief	メッセージ出力
	 * @param	stream	出力するストリームオブジェクト
	 * @param	msg		出力文字列
	 */
	virtual void WriteMessge(const char * msg) = 0;

	/**
	 * @brief	警告出力
	 * @param	stream	出力するストリームオブジェクト
	 * @param	msg		出力文字列
	 */
	virtual void WriteWarning(const char * msg) = 0;

	/**
	 * @brief	エラー出力
	 * @param	stream	出力するストリームオブジェクト
	 * @param	msg		出力文字列
	 */
	virtual void WriteError(const char * msg) = 0;

	/**
	 * @brief	例外情報出力
	 * @param	stream	出力するストリームオブジェクト
	 * @param	ex		例外オブジェクト
	 */
	virtual void WriteException(const std::exception &ex) = 0;

	/**
	 * @brief	デバッグ情報出力
	 * @param	stream	出力するストリームオブジェクト
	 * @param	msg		出力文字列
	 */
	virtual void WriteDebug(const char * msg) = 0;

}; /* CLogStreamInterface */

#endif /* __YOKOYAMA51_LOGSTREAM_INTERFACE_H__ */
