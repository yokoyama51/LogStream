

/**
 * @brief	CLogStream�N���X��`�t�@�C��
 */

#include "logstream.h"

#include <map>
#include <string>
#include <boost/assign.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;


/**
 * @brief	�R���X�g���N�^
 */
CLogStream::CLogStream()
{
}


/**
 * @brief	�f�X�g���N�^
 */
CLogStream::~CLogStream()
{
}


/**
 * @brief	�X�g���[���ւ̏o��
 *
 * @param	type	�o�͎��
 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogStream::_Write(LogType type, std::ostream &stream, const char * msg)
{
	// �����擾
	boost::posix_time::ptime now_(boost::posix_time::microsec_clock::local_time());

	// �����o�̓t�H�[�}�b�g�ݒ�
	boost::posix_time::time_facet * f = new boost::posix_time::time_facet("%Y/%m/%d %H:%M:%S.%f");
	std::stringstream ss;
	ss.imbue(std::locale(ss.getloc(), f));
	//delete f; time_facet�̉����locale�I�u�W�F�N�g�����{����̂ŁA�����I��delete�͕s�v

	using namespace boost::assign; 
	static map<LogType, string> _map = map_list_of(LOG_INFOMATION, "INFO")(LOG_MESSAGE, "MESSAGE")(LOG_ERROR, "ERROR")(LOG_WARNING, "WARNING")(LOG_EXCEPTION, "EXCEPTION")(LOG_DEBUG, "DEBUG");
	map<LogType, string>::iterator it = _map.find(type);
	assert(it != _map.end()); // �K���q�b�g����͂�

	ss << now_ << " [" << (*it).second << "] " << msg << "\n";
	const string &s = ss.str();
	stream.write(s.c_str(), s.length()); // �o��
}


/**
 * @brief	�C���t�H���[�V�����o��
 *
 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
 * @param	msg		�o�͕�����
 */
void CLogStream::_WriteInfomation(std::ostream &stream, const char * msg)
{
	_Write(LOG_INFOMATION, stream, msg);
}


/**
 * @brief	���b�Z�[�W�o��
 *
 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
 * @param	msg		�o�͕�����
 */
void CLogStream::_WriteMessge(std::ostream &stream, const char * msg)
{
	_Write(LOG_MESSAGE, stream, msg);
}


/**
 * @brief	�x���o��
 *
 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
 * @param	msg		�o�͕�����
 */
void CLogStream::_WriteWarning(std::ostream &stream, const char * msg)
{
	_Write(LOG_WARNING, stream, msg);
}


/**
 * @brief	�G���[�o��
 *
 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
 * @param	msg		�o�͕�����
 */
void CLogStream::_WriteError(std::ostream &stream, const char * msg)
{
	_Write(LOG_ERROR, stream, msg);
}


/**
 * @brief	��O���o��
 *
 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
 * @param	ex		��O�I�u�W�F�N�g
 */
void CLogStream::_WriteException(std::ostream &stream, const std::exception &ex)
{
	_Write(LOG_EXCEPTION, stream, ex.what());
}


/**
 * @brief	�f�o�b�O���o��
 *
 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
 * @param	msg		�o�͕�����
 *
 * @note	�{�֐��̓f�o�b�O���[�h���̂ݎ��s�����
 */
void CLogStream::_WriteDebug(std::ostream &stream, const char * msg)
{
#ifndef NDEBUG
	_Write(LOG_DEBUG, stream, msg);
#endif /* NDEBUG */
}