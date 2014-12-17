

/**
 * @brief	CLogStream�N���X�錾�t�@�C��
 */

#ifndef __YOKOYAMA51_LOGSTREAM_H__
#define __YOKOYAMA51_LOGSTREAM_H__


#include "logstreaminterface.h"

#include <ostream>


/**
 * @brief	���O�o�̓I�u�W�F�N�g
 */
class CLogStream : public CLogStreamInterface
{
public: // �\�z/�j��
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
	/* @brief ���O�o�͎�� */
	enum LogType { LOG_INFOMATION=0, ///< ���
				   LOG_MESSAGE,		 ///< ���b�Z�[�W
				   LOG_ERROR,		 ///< �G���[
				   LOG_WARNING,		 ///< �x��
				   LOG_EXCEPTION,	 ///< ��O
				   LOG_DEBUG };		 ///< �f�o�b�O���o��

	static void _Write(LogType type, std::ostream &stream, const char * msg);

}; /* CLogStream */

#endif /* __YOKOYAMA51_LOGSTREAM_H__ */
