

/**
 * @brief	CLogStreamInterface�N���X�錾�t�@�C��
 */

#ifndef __YOKOYAMA51_LOGSTREAM_INTERFACE_H__
#define __YOKOYAMA51_LOGSTREAM_INTERFACE_H__

#include <exception>


/**
 * @brief	���O�o�̓C���^�[�t�F�[�X
 */
class CLogStreamInterface
{
public: 
	virtual ~CLogStreamInterface() {}

public: // �������z�֐�/�C���^�[�t�F�[�X��`
	/**
	 * @brief	�C���t�H���[�V�����o��
	 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
	 * @param	msg		�o�͕�����
	 */
	virtual void WriteInfomation(const char * msg) = 0;

	/**
	 * @brief	���b�Z�[�W�o��
	 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
	 * @param	msg		�o�͕�����
	 */
	virtual void WriteMessge(const char * msg) = 0;

	/**
	 * @brief	�x���o��
	 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
	 * @param	msg		�o�͕�����
	 */
	virtual void WriteWarning(const char * msg) = 0;

	/**
	 * @brief	�G���[�o��
	 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
	 * @param	msg		�o�͕�����
	 */
	virtual void WriteError(const char * msg) = 0;

	/**
	 * @brief	��O���o��
	 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
	 * @param	ex		��O�I�u�W�F�N�g
	 */
	virtual void WriteException(const std::exception &ex) = 0;

	/**
	 * @brief	�f�o�b�O���o��
	 * @param	stream	�o�͂���X�g���[���I�u�W�F�N�g
	 * @param	msg		�o�͕�����
	 */
	virtual void WriteDebug(const char * msg) = 0;

}; /* CLogStreamInterface */

#endif /* __YOKOYAMA51_LOGSTREAM_INTERFACE_H__ */
