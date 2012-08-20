/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2012 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __KBE_DB_INTERFACE__
#define __KBE_DB_INTERFACE__

#include "cstdkbe/cstdkbe.hpp"
#include "cstdkbe/singleton.hpp"
#include "helper/debug_helper.hpp"

namespace KBEngine { 

class DBUtil;

/*
	���ݿ�ӿ�
*/
class DBInterface
{
public:
	friend class DBUtil;
	DBInterface(){};
	virtual ~DBInterface(){};

	/**
		��ĳ�����ݿ����
	*/
	virtual bool attach(const char* databaseName) = 0;
	virtual bool detach() = 0;

	/**
	 ��ѯ��
	*/
	virtual bool query(const char* strCommand) = 0;

	/**
		��������ӿڵ�����
	*/
	virtual const char* c_str() = 0;
protected:
	char db_type_[MAX_BUF];									// ���ݿ�����
	uint32 db_port_;										// ���ݿ�Ķ˿�
	char db_ip_[MAX_IP];									// ���ݿ��ip��ַ
	char db_username_[MAX_BUF];								// ���ݿ���û���
	char db_password_[MAX_BUF];								// ���ݿ������
	char db_name_[MAX_BUF];									// ���ݿ���
	uint16 db_numConnections_;								// ���ݿ��������
};

/*
	���ݿ������Ԫ
*/
class DBUtil : public Singleton<DBUtil>
{
public:
	DBUtil();
	~DBUtil();

	static DBInterface* create(const char* dbtype, const char* ip, uint32 port, const char* db_username, 
		const char* db_password, uint16 db_numConnections);
private:

};

}

#endif // __KBE_DB_INTERFACE__