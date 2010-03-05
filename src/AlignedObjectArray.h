#pragma once

#include "Dbvt.h"
#include "IDisposable.h"

namespace BulletSharp
{
	ref class CollisionObject;
	ref class CollisionShape;
	ref class PersistentManifold;

	public ref class AlignedObjectArray : BulletSharp::IDisposable
	{
	public:
		virtual event EventHandler^ OnDisposing;
		virtual event EventHandler^ OnDisposed;

	private:
		void* _alignedObjectArray;

	internal:
		AlignedObjectArray(void* alignedObjectArray);
	public:
		!AlignedObjectArray();
	protected:
		~AlignedObjectArray();

	public:
		property bool IsDisposed
		{
			virtual bool get();
		}

	internal:
		property void* UnmanagedPointer
		{
			virtual void* get();
			void set(void* value);
		}
	};

	public ref class CollisionShapeArray : AlignedObjectArray
	{
	public:
		CollisionShapeArray();

		void Clear();
		void PopBack();
		void PushBack(CollisionShape^ collisionShape);
		void Remove(CollisionShape^ collisionShape);
		void Swap(int index0, int index1);

		property int Capacity
		{
			int get();
		}

		property int Size
		{
			int get();
		}

		property CollisionShape^ default [int]
		{
			CollisionShape^ get (int index);
			void set(int index, CollisionShape^);
		}

	internal:
		property btAlignedObjectArray<btCollisionShape*>* UnmanagedPointer
		{
			btAlignedObjectArray<btCollisionShape*>* get() new;
		}
	};

	public ref class CollisionObjectArray : AlignedObjectArray
	{
	internal:
		CollisionObjectArray(btCollisionObjectArray* collisionObjectArray);

	public:
		CollisionObjectArray();

		void Clear();
		void PopBack();
		void PushBack(CollisionObject^ collisionObject);
		void Remove(CollisionObject^ collisionObject);
		void Swap(int index0, int index1);

		property int Size
		{
			int get();
		}

		property int Capacity
		{
			int get();
		}

		property CollisionObject^ default [int]
		{
			CollisionObject^ get (int index);
			void set(int index, CollisionObject^);
		}

	internal:
		property btCollisionObjectArray* UnmanagedPointer
		{
			virtual btCollisionObjectArray* get() new;
		}
	};

	public ref class DbvtNodeArray : AlignedObjectArray
	{
	internal:
		DbvtNodeArray(btAlignedObjectArray<const btDbvtNode*>* nodeArray);

	public:
		DbvtNodeArray();

		void Clear();
		void PopBack();
		void PushBack(DbvtNode^ stkNps);
		void Remove(DbvtNode^ stkNps);
		void Swap(int index0, int index1);

		property int Size
		{
			int get();
		}

		property int Capacity
		{
			int get();
		}

		property DbvtNode^ default [int]
		{
			DbvtNode^ get (int index);
			void set(int index, DbvtNode^);
		}

	internal:
		property btAlignedObjectArray<const btDbvtNode*>* UnmanagedPointer
		{
			virtual btAlignedObjectArray<const btDbvtNode*>* get() new;
		}
	};

	public ref class IntArray : AlignedObjectArray
	{
	internal:
		IntArray(btAlignedObjectArray<int>* intArray);

	public:
		IntArray();

		void Clear();
		void PopBack();
		void PushBack(int manifold);
		void Remove(int manifold);
		void Swap(int index0, int index1);

		property int Size
		{
			int get();
		}

		property int Capacity
		{
			int get();
		}

		property int default [int]
		{
			int get (int index);
			void set(int index, int);
		}

	internal:
		property btAlignedObjectArray<int>* UnmanagedPointer
		{
			virtual btAlignedObjectArray<int>* get() new;
		}
	};

	public ref class ManifoldArray : AlignedObjectArray
	{
	internal:
		ManifoldArray(btManifoldArray* manifoldArray);

	public:
		ManifoldArray();

		void Clear();
		void PopBack();
		void PushBack(PersistentManifold^ manifold);
		void Remove(PersistentManifold^ manifold);
		void Swap(int index0, int index1);

		property int Size
		{
			int get();
		}

		property int Capacity
		{
			int get();
		}

		property PersistentManifold^ default [int]
		{
			PersistentManifold^ get (int index);
			void set(int index, PersistentManifold^);
		}

	internal:
		property btManifoldArray* UnmanagedPointer
		{
			virtual btManifoldArray* get() new;
		}
	};

	public ref class StkNnArray : AlignedObjectArray
	{
	internal:
		StkNnArray(btAlignedObjectArray<btDbvt::sStkNN>* stkNnArray);

	public:
		StkNnArray();

		void Clear();
		void PopBack();
		void PushBack(Dbvt::StkNn^ stkNps);
		void Remove(Dbvt::StkNn^ stkNps);
		void Swap(int index0, int index1);

		property int Size
		{
			int get();
		}

		property int Capacity
		{
			int get();
		}

		property Dbvt::StkNn^ default [int]
		{
			Dbvt::StkNn^ get (int index);
			void set(int index, Dbvt::StkNn^);
		}

	internal:
		property btAlignedObjectArray<btDbvt::sStkNN>* UnmanagedPointer
		{
			virtual btAlignedObjectArray<btDbvt::sStkNN>* get() new;
		}
	};

	public ref class StkNpsArray : AlignedObjectArray
	{
	internal:
		StkNpsArray(btAlignedObjectArray<btDbvt::sStkNPS>* stkNpsArray);

	public:
		StkNpsArray();

		void Clear();
		void PopBack();
		void PushBack(Dbvt::StkNps^ stkNps);
		void Remove(Dbvt::StkNps^ stkNps);
		void Swap(int index0, int index1);

		property int Size
		{
			int get();
		}

		property int Capacity
		{
			int get();
		}

		property Dbvt::StkNps^ default [int]
		{
			Dbvt::StkNps^ get (int index);
			void set(int index, Dbvt::StkNps^);
		}

	internal:
		property btAlignedObjectArray<btDbvt::sStkNPS>* UnmanagedPointer
		{
			virtual btAlignedObjectArray<btDbvt::sStkNPS>* get() new;
		}
	};
};