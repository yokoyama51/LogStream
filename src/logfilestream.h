

/**
 * @brief	CLogFileStream�N���X�錾�t�@�C��
 */

#ifndef __YOKOYAMA51_LOGFILEWRITER_H__
#define __YOKOYAMA51_LOGFILEWRITER_H__

#include "logstream.h"

#include <string>
#include <fstream>
#include <boost/function.hpp>


/**
 * @brief	���O�t�@�C���o��
 *
 * @note	m_directory�ȉ��ɔN�ʃt�H���_���쐬�����t���ƂɃ��O�t�@�C�����쐬����<br>
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
public: // �\�z/�j��
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
	std::string m_directory; ///< �o�̓f�B���N�g��
	std::string m_prefix;	 ///< ���O�t�@�C���v���t�B�N�X
}; /* CLogFileStream */

#endif /* __YOKOYAMA51_LOGFILEWRITER_H__ */
