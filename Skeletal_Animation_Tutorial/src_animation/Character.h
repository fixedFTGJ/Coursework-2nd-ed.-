#pragma once

namespace CourseWork
{
	class Character
	{
	public:
		Character(int health, int armor, int damage, int dodge);
		void Attack(Character* target);
		void ReceiveDamage(int damage);
		bool IsDodge();
		bool IsDead();
		void SetHealth(int health) { _health = health; };
		int GetHealth() { return _health; };
		void SetDamage(int damage) { _damage = damage; };
		int GetDamage() { return _damage; };
		void SetArmor(int armor) { _armor = armor; };
		int GetArmor() { return _armor; };
		void SetDodge(int dodge) { _dodge = dodge; };
		int GetDodge() { return _dodge; };
		int GetHealthLimit() { return _healthLimit; };
	protected:
		int _healthLimit;
		int _health;
		int _armor;
		int _damage;
		int _dodge;
		bool _isDead;
	};
}
