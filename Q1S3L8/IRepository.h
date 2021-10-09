#pragma once

class IRepository {
	virtual void Open() = 0;
	virtual void Save() = 0;
};