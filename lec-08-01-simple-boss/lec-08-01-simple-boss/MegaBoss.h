#include "simple_boss.h"

class MegaBoss : public Boss
{
public:
	int m_MegaDamageMultiplier;

	MegaBoss();
	void MegaAttack() const;
	~MegaBoss();
};
