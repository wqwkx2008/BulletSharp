#include "StdAfx.h"

#include "CollisionConfiguration.h"
#include "CollisionCreateFunc.h"
#include "StackAlloc.h"
#ifndef DISABLE_UNCOMMON
#include "PoolAllocator.h"
#endif

CollisionConfiguration::CollisionConfiguration(btCollisionConfiguration* collisionConfiguration)
{
	_collisionConfiguration = collisionConfiguration;
}

CollisionConfiguration::~CollisionConfiguration()
{
	this->!CollisionConfiguration();
}

CollisionConfiguration::!CollisionConfiguration()
{
	delete _collisionConfiguration;
	_collisionConfiguration = NULL;
}

CollisionAlgorithmCreateFunc^ CollisionConfiguration::GetCollisionAlgorithmCreateFunc(BroadphaseNativeType proxyType0, BroadphaseNativeType proxyType1)
{
	return gcnew CollisionAlgorithmCreateFunc(_collisionConfiguration->getCollisionAlgorithmCreateFunc((int)proxyType0, (int)proxyType1));
}

bool CollisionConfiguration::IsDisposed::get()
{
	return (_collisionConfiguration == NULL);
}

#ifndef DISABLE_UNCOMMON
PoolAllocator^ CollisionConfiguration::CollisionAlgorithmPool::get()
{
	return gcnew PoolAllocator(_collisionConfiguration->getCollisionAlgorithmPool());
}

PoolAllocator^ CollisionConfiguration::PersistentManifoldPool::get()
{
	return gcnew PoolAllocator(_collisionConfiguration->getPersistentManifoldPool());
}
#endif

StackAlloc^ CollisionConfiguration::StackAllocator::get()
{
	return gcnew StackAlloc(_collisionConfiguration->getStackAllocator());
}

btCollisionConfiguration* CollisionConfiguration::UnmanagedPointer::get()
{
	return _collisionConfiguration;
}
void CollisionConfiguration::UnmanagedPointer::set( btCollisionConfiguration* value )
{
	_collisionConfiguration = value;
}
