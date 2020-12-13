#pragma once

class exceptions {
protected:
	int code;
public:
	explicit exceptions(int code = 0) { this->code = code; }
	virtual void ErrorText() {};
};

