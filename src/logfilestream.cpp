


/**
 * @brief	CLogFileStream�N���X��`�t�@�C��
 */

#include "logfilestream.h"

#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;


/**
 * @brief	�R���X�g���N�^
 */
CLogFileStream::CLogFileStream()
{
	SetDirectoryAndPrefix("./log", "app");
}


/**
 * @brief	�R���X�g���N�^
 *
 * @param	directory	�o�̓f�B���N�g��
 * @param	prefix		���O�t�@�C���v���t�B�N�X����
 */
CLogFileStream::CLogFileStream(const char * directory, const char * prefix)
{
	SetDirectoryAndPrefix(directory, prefix);
}


/**
 * @brief	�f�X�g���N�^
 */
CLogFileStream::~CLogFileStream()
{
}


/**
 * @brief	�o�̓f�B���N�g���Əo�̓t�@�C���v���t�B�N�X�����̐ݒ�
 *
 * @param	directory	�o�̓f�B���N�g��
 * @param	prefix		���O�t�@�C���v���t�B�N�X����
 */
void CLogFileStream::SetDirectoryAndPrefix(const char * directory, const char * prefix)
{
	boost::filesystem::path path(directory);
	boost::filesystem::path abs = boost::filesystem::absolute(path);

	m_directory = abs.string();
	m_prefix = prefix;
}


/**
 * @brief	�o�̓t�@�C���p�X�擾
 *
 * @param[out]	out		�t�@�C���p�X���i�[����o�b�t�@
 */
void CLogFileStream::GetFilePath(std::string &out)
{
	// �����擾
	boost::posix_time::ptime now_(boost::posix_time::second_clock::local_time());

	// �o�̓f�B���N�g��
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
 * @brief	�o�͊֐����Ăяo���A�t�@�C���ɏo�͂���
 *
 * @param	write_func	�o�͊֐��I�u�W�F�N�g
 */
void CLogFileStream::Write(boost::function<void (std::ofstream&)> &write_func)
{
	string path;
	GetFilePath(path);

	ofstream stream(path.c_str(), ios::out|ios::app); // ���O�t�@�C���͒ǋL����
	if(stream.is_open()){
		write_func(stream);
	}
}


/**
 * @brief	�C���t�H���[�V�����o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogFileStream::WriteInfomation(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteInfomation, _1, msg);
	Write(f);
}


/**
 * @brief	���b�Z�[�W�o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogFileStream::WriteMessge(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteMessge, _1, msg);
	Write(f);
}


/**
 * @brief	�x���o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogFileStream::WriteWarning(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteWarning, _1, msg);
	Write(f);
}


/**
 * @brief	�G���[�o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogFileStream::WriteError(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteError, _1, msg);
	Write(f);
}


/**
 * @brief	��O�o��
 *
 * @param	ex		��O�I�u�W�F�N�g
 */
void CLogFileStream::WriteException(const std::exception &ex)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteException, _1, ex);
	Write(f);
}


/**
 * @brief	�f�o�b�O���o��
 *
 * @param	msg		�o�͕�����
 *
 * @note	�{�֐��̓f�o�b�O���[�h���̂ݎ��s�����
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogFileStream::WriteDebug(const char * msg)
{
	boost::function<void (std::ofstream&)> f;
	f = boost::bind(&CLogStream::_WriteDebug, _1, msg);
	Write(f);
}



