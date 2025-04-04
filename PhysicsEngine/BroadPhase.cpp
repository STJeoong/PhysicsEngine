#include "pch.h"
#include "BroadPhase.h"
#include <vector>

std::vector<int> v;
#pragma region public
int BroadPhase::insert(void* userData, const AABB& aabb)
{
	int ret = _tree.insert(userData, aabb);
	_thingsToBeUpdated.push_back(ret);
	/*for (int i = 0; i < v.size(); ++i)
		_candidates.push_back({v[i], ret});
	v.push_back(ret);*/
	return ret;
}
void BroadPhase::remove(int id)
{
	auto it = std::find(_thingsToBeUpdated.begin(), _thingsToBeUpdated.end(), id);
	if (it != _thingsToBeUpdated.end()) _thingsToBeUpdated.erase(it);
	_tree.remove(id);
}
bool BroadPhase::move(int id, const AABB& sweepAABB, const Vector2D& displacement)
{
	bool wasMoved = _tree.move(id, sweepAABB, displacement);
	if (wasMoved)
	{
		auto it = std::find(_thingsToBeUpdated.begin(), _thingsToBeUpdated.end(), id);
		if (it == _thingsToBeUpdated.end())
			_thingsToBeUpdated.push_back(id);
	}
	return wasMoved;
}
void BroadPhase::update()
{
	_candidates.clear();
	if (!_thingsToBeUpdated.empty())
	{
		_tree.makeCandidates(_thingsToBeUpdated, _candidates);
		_thingsToBeUpdated.clear();
	}
}
#pragma endregion

#pragma region private
#pragma endregion
