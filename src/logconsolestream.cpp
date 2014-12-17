

/**
 * @brief	CLogConsoleWriter�N���X��`�t�@�C��
 */

#include "logconsolestream.h"

#include <iostream>

using namespace std;


/**
 * @brief	�R���X�g���N�^
 */
CLogConsoleWriter::CLogConsoleWriter()
{
}


/**
 * @brief	�f�X�g���N�^
 */
CLogConsoleWriter::~CLogConsoleWriter()
{
}


/**
 * @brief	�C���t�H���[�V�����o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogConsoleWriter::WriteInfomation(const char * msg)
{
	CLogStream::_WriteInfomation(std::cout, msg);
}


/**
 * @brief	���b�Z�[�W�o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogConsoleWriter::WriteMessge(const char * msg)
{
	CLogStream::_WriteMessge(std::cout, msg);
}


/**
 * @brief	�x���o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogConsoleWriter::WriteWarning(const char * msg)
{
	CLogStream::_WriteWarning(std::cout, msg);
}


/**
 * @brief	�G���[�o��
 *
 * @param	msg		�o�͕�����
 *
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogConsoleWriter::WriteError(const char * msg)
{
	CLogStream::_WriteError(std::cout, msg);
}


/**
 * @brief	��O�o��
 *
 * @param	ex		��O�I�u�W�F�N�g
 */
void CLogConsoleWriter::WriteException(const std::exception &ex)
{
	CLogStream::_WriteException(std::cout, ex);
}


/**
 * @brief	�f�o�b�O���o��
 *
 * @param	msg		�o�͕�����
 *
 * @note	�{�֐��̓f�o�b�O���[�h���̂ݎ��s�����
 * @warning	msg���̉��s�R�[�h�͓��ɔ��肵�Ȃ��B���̂��߁A���s�R�[�h���܂܂��ꍇ�̓t�H�[�}�b�g�������
 */
void CLogConsoleWriter::WriteDebug(const char * msg)
{
	CLogStream::_WriteDebug(std::cout, msg);
}



