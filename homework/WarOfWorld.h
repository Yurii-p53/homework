
#pragma once

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<Windows.h>

#include"List.h"

using namespace std;

enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

class Warrior;


class Skill
{
	int uses;

public:
	Skill(int uses = 2) : uses(uses) {}

	virtual ~Skill() {}

	int getUses()
	{
		return uses;
	}

	virtual void execute(Warrior* w) = 0;

	void use(Warrior* w)
	{
		if (uses > 0)
		{
			execute(w);
			uses--;
		}
		else
		{
			SetColor(Yellow, Black);
			cout << "No skill charges left!" << endl;
			SetColor(White, Black);
		}
	}
};


class FireBall : public Skill
{
public:
	FireBall() : Skill(3) {}

	virtual void execute(Warrior* w) override;
};


class Warrior
{
	int hp;
	int damage;

protected:
	Skill* skill;

public:
	Warrior(int hp, int damage, Skill* skill = nullptr) : hp(hp), damage(damage), skill(skill) {}

	virtual ~Warrior()
	{
		delete skill;
	}

	int getHP()
	{
		return hp;
	}

	int getDamage()
	{
		return damage;
	}

	void setHP(int h)
	{
		hp = h;

		if (hp < 0)
			hp = 0;
	}

	void setDamage(int d)
	{
		damage = d;
	}

	void takeDamage(int d)
	{
		hp -= d;

		if (hp < 0)
			hp = 0;
	}

	void useSkill(Warrior* w)
	{
		if (skill)
			skill->use(w);
	}

	virtual void attack(Warrior* w) = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);

	virtual ostream& print(ostream& out) const
	{
		out << " HP: " << hp
			<< ", Damage: " << damage << endl;

		if (skill)
			out << " Skill charges: " << skill->getUses() << endl;

		return out;
	}
};


ostream& operator<<(ostream& out, const Warrior* w)
{
	if (w != nullptr)
	{
		out << setw(12) << left << setfill('.');
		w->print(out);
		out << setfill(' ');
	}

	return out;
}


void FireBall::execute(Warrior* w)
{
	if (w != nullptr && w->getHP() > 0)
	{
		SetColor(LightRed, Black);
		cout << "FIREBALL! Extra damage: 15" << endl;
		SetColor(White, Black);

		w->takeDamage(15);
	}
}


class Light : public Warrior
{
public:
	Light(int hp, int damage, Skill* skill = nullptr)
		: Warrior(hp, damage, skill) {
	}
};


class Dark : public Warrior
{
public:
	Dark(int hp, int damage) : Warrior(hp, damage) {}
};


class Archer : public Light
{
public:
	Archer(int hp, int damage, Skill* skill = nullptr)
		: Light(hp, damage, skill) {
	}

	virtual void attack(Warrior* w) override
	{
		if (w == nullptr || getHP() <= 0 || w->getHP() <= 0)
			return;

		SetColor(LightGreen, Black);
		cout << "Archer attacks!" << endl;
		SetColor(White, Black);

		w->takeDamage(getDamage());

		if (skill && w->getHP() > 0)
			useSkill(w);
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Archer";
		return Warrior::print(out);
	}
};


class Rider : public Light
{
public:
	Rider(int hp, int damage, Skill* skill = nullptr)
		: Light(hp, damage, skill) {
	}

	virtual void attack(Warrior* w) override
	{
		if (w == nullptr || getHP() <= 0 || w->getHP() <= 0)
			return;

		SetColor(LightCyan, Black);
		cout << "Rider attacks with a powerful charge!" << endl;
		SetColor(White, Black);

		w->takeDamage(getDamage() + 5);
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Rider";
		return Warrior::print(out);
	}
};


class Swordsman : public Light
{
public:
	Swordsman(int hp, int damage, Skill* skill = nullptr)
		: Light(hp, damage, skill) {
	}

	virtual void attack(Warrior* w) override
	{
		if (w == nullptr || getHP() <= 0 || w->getHP() <= 0)
			return;

		SetColor(Yellow, Black);
		cout << "Swordsman strikes!" << endl;
		SetColor(White, Black);

		w->takeDamage(getDamage());
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Swordsman";
		return Warrior::print(out);
	}
};


class Ork : public Dark
{
public:
	Ork(int hp, int damage) : Dark(hp, damage) {}

	virtual void attack(Warrior* w) override
	{
		if (w == nullptr || getHP() <= 0 || w->getHP() <= 0)
			return;

		SetColor(LightRed, Black);
		cout << "Ork smashes the enemy!" << endl;
		SetColor(White, Black);

		w->takeDamage(getDamage() + 3);
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Ork";
		return Warrior::print(out);
	}
};


class Zombe : public Dark
{
public:
	Zombe(int hp, int damage) : Dark(hp, damage) {}

	virtual void attack(Warrior* w) override
	{
		if (w == nullptr || getHP() <= 0 || w->getHP() <= 0)
			return;

		SetColor(Green, Black);
		cout << "Zombe attacks!" << endl;
		SetColor(White, Black);

		w->takeDamage(getDamage());
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Zombe";
		return Warrior::print(out);
	}
};


class Skeleton : public Dark
{
public:
	Skeleton(int hp, int damage) : Dark(hp, damage) {}

	virtual void attack(Warrior* w) override
	{
		if (w == nullptr || getHP() <= 0 || w->getHP() <= 0)
			return;

		SetColor(LightMagenta, Black);
		cout << "Skeleton attacks with a bone!" << endl;
		SetColor(White, Black);

		w->takeDamage(getDamage());
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Skeleton";
		return Warrior::print(out);
	}
};


class WarOfWord
{
	List<Light*> ligts;
	List<Dark*> darks;

public:
	WarOfWord(int size)
	{
		srand((unsigned int)time(0));

		Light* l = nullptr;

		for (int i = 0; i < size; i++)
		{
			int rnd = rand() % 3;

			switch (rnd)
			{
			case 0:
				l = new Archer(rand() % 20 + 50, rand() % 10 + 10, new FireBall);
				break;

			case 1:
				l = new Rider(rand() % 30 + 50, rand() % 10 + 10);
				break;

			case 2:
				l = new Swordsman(rand() % 20 + 50, rand() % 10 + 10);
				break;
			}

			ligts.push_back(l);
		}

		Dark* d = nullptr;

		for (int i = 0; i < size; i++)
		{
			int rnd = rand() % 3;

			switch (rnd)
			{
			case 0:
				d = new Ork(rand() % 20 + 50, rand() % 10 + 10);
				break;

			case 1:
				d = new Zombe(rand() % 30 + 50, rand() % 10 + 10);
				break;

			case 2:
				d = new Skeleton(rand() % 20 + 50, rand() % 10 + 10);
				break;
			}

			darks.push_back(d);
		}
	}

	~WarOfWord()
	{
		for (size_t i = 0; i < ligts.getSize(); i++)
			delete ligts[i];

		for (size_t i = 0; i < darks.getSize(); i++)
			delete darks[i];
	}

	void print()
	{
		SetColor(LightGreen, Black);
		cout << "========== LIGHT ARMY ==========" << endl;
		SetColor(White, Black);

		ligts.print();

		cout << endl;

		SetColor(LightRed, Black);
		cout << "========== DARK ARMY ===========" << endl;
		SetColor(White, Black);

		darks.print(40, 1);
	}

	void game()
	{
		int round = 1;

		while (ligts.getSize() > 0 && darks.getSize() > 0)
		{
			system("cls");

			SetColor(LightCyan, Black);
			cout << "========================================" << endl;
			cout << "              WAR OF WORLD              " << endl;
			cout << "========================================" << endl;
			SetColor(White, Black);

			cout << "Round: " << round << endl << endl;

			print();

			int l_ind = rand() % ligts.getSize();
			int d_ind = rand() % darks.getSize();

			cout << endl;
			SetColor(Yellow, Black);
			cout << "--------------- FIGHT ------------------" << endl;
			SetColor(White, Black);

			cout << "LIGHT: ";
			cout << ligts[l_ind] << endl;

			cout << "DARK:  ";
			cout << darks[d_ind] << endl;

			Warrior* lose = fight(ligts[l_ind], darks[d_ind]);

			if (lose == ligts[l_ind])
			{
				SetColor(LightRed, Black);
				cout << "LIGHT warrior lost!" << endl;
				SetColor(White, Black);

				delete ligts[l_ind];
				ligts.remove(l_ind);
			}
			else if (lose == darks[d_ind])
			{
				SetColor(LightRed, Black);
				cout << "DARK warrior lost!" << endl;
				SetColor(White, Black);

				delete darks[d_ind];
				darks.remove(d_ind);
			}

			cout << endl;
			SetColor(LightCyan, Black);
			cout << "Light warriors left: " << ligts.getSize() << endl;
			cout << "Dark warriors left: " << darks.getSize() << endl;
			SetColor(White, Black);

			round++;

			system("pause");
		}

		system("cls");

		SetColor(Yellow, Black);
		cout << "========================================" << endl;
		cout << "               GAME OVER                " << endl;
		cout << "========================================" << endl;
		SetColor(White, Black);

		if (ligts.getSize() > 0)
		{
			SetColor(LightGreen, Black);
			cout << "        LIGHT ARMY WINS!" << endl;
		}
		else
		{
			SetColor(LightRed, Black);
			cout << "         DARK ARMY WINS!" << endl;
		}

		SetColor(White, Black);

		cout << endl;
		cout << "Press any key to exit..." << endl;
		system("pause");
	}

	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		Warrior* f = w1;
		Warrior* s = w2;

		while (f->getHP() > 0 && s->getHP() > 0)
		{
			cout << endl;

			f->attack(s);

			SetColor(LightGray, Black);
			cout << "Enemy HP: " << s->getHP() << endl;
			SetColor(White, Black);

			if (s->getHP() <= 0)
				break;

			s->attack(f);

			SetColor(LightGray, Black);
			cout << "Warrior HP: " << f->getHP() << endl;
			SetColor(White, Black);

			if (f->getHP() <= 0)
				break;
		}

		if (w1->getHP() <= 0)
			return w1;

		return w2;
	}
};
