//#pragma once
//#pragma once
//#pragma once
//
//#include "framework.h"
//#include <Windows.h>
//#include <cstdio>
//#include <cstring>
//
//
//#define GRID_SIZE 16
//
//enum class TreeColor
//{
//	BLACK = 0,
//	RED = 1
//};
//
//
//struct Node
//{
//	
//	Node* parent = nullptr;
//	Node* left = nullptr;
//	Node* right = nullptr;
//	int _Key = {};
//	
//	TreeColor color = TreeColor::BLACK;
//};
//
//
//class RedBlackTree
//{
//public:
//
//	RedBlackTree()
//	{
//		nil = new Node();
//		root = nil;
//	}
//
//	Node* minNode(Node* node)		// �� �״�� Node ���� ���� ���� ���� left left left
//	{
//		while (node->left != nil)
//		{
//			node = node->left;
//		}
//
//		return node;
//	}
//
//	Node* maxNode(Node* node)		// �� �״�� Node ���� ���� ū ���� right right ...
//	{
//		while (node->right != nil)
//		{
//			node = node->right;
//		}
//
//		return node;
//	}
//
//	Node* next(Node* node)	// Node ���� ���� ���� ����? 
//	{
//		if (node->right != nil)			// Right�� �ִٸ� 
//			// ���� Ʈ�� ����
//		{
//			return minNode(node->right);		// Right�� ���� ������ �ִ� ���� �� ����.
//		}
//

//
//
////  Right�� ��� �θ� Ÿ�� ������ ��. �ٵ� �θ� ���� ���� �ƴ� �� ����
////  Parent�� Ÿ�� ���µ�, Parent�� �� Parent�� ������ �ִ� ��츦 ���ַ�����
////  �� ��尡 �θ��� ���� ������ ������ ������ �ȵ�. ���� ���� �ƴ�.
//
//		Node* parent = node->parent;
//		while (parent != nil && node == parent->right)	// node �� parent�� right�� �ִ� ��쿡�� ���
//		{
//			node = parent;
//			parent = parent->parent;
//		}
//
// 

//
//
//		return parent;	// ������ �ƴ� �θ� ���� ���� ��.
//	}
//
//	//void rotation_Right(Node* n)				���� �����̼�
//	//{
//	//	// 1. N �� ���� �ڽ��� ���� ���� N�� ����, n�� ���� �ڽ��� ���� ������ ��
//
//	//		// ���� N�� Left ����
//	//	Node* Origin_Left = n->left;
//
//	//		// Left�� ����������, n�� ���� ���� Origin_left �� ���� ������ �ٲ�
//	//	n->left = Origin_Left->right;
//	//	Origin_Left->right->parent = n;
//	//	
//	//	// 2. N �� ���� ���� �ڽ��� N�� �ڸ��� �ø�
//	//		
//	//	Origin_Left->right = n;
//	//	Origin_Left->parent = n->parent;
//	//	n->parent = Origin_Left;
//	//	
//

//	//}
//
//	/*void rotation_Left(Node* n)		// ���� �����̼�
//	{
//		Node* Origin_Right = n->right;
//
//		Origin_Right->left->parent = n->right;
//		n->right = Origin_Right->left;
//		
//		Origin_Right->left = n;
//		Origin_Right->parent = n->parent;
//		n->parent = Origin_Right;
//
//	}*/
//
//
//
//
//
//
//
//	//void insert_Check(Node* node)
//	//{
//	//	// ������ ����	// ���� ����� ������, 4�� ��Ģ
//	//	// 1. �θ� ����, ���� ����
//	//	// 2. �θ� ����, ���� ��, ���� ����
//	//	// 3. �θ� ����
//
//	//	while (node->parent->color == TreeColor::RED)
//	//	{
//	//		// �θ� ��ü�� Right�� ���
//	//		if (node->parent == node->parent->parent->right)
//	//		{
//	//			Node* Uncle = node->parent->parent->left;
//
//	//			if (Uncle->color == TreeColor::RED)
//	//			{
//	//				node->parent->parent->left->color = TreeColor::BLACK;
//	//				node->parent->color = TreeColor::BLACK;
//	//				node->parent->parent->color = TreeColor::RED;
//	//				node = node->parent->parent;
//	//			}
//	//			// ������ ���� ���
//	//			else
//	//			{
//	//				if (node == node->parent->left)	// ���� ������ ���
//	//				{
//	//					node = node->parent;
//	//					rotation_Right(node->parent);
//	//				}
//	//				                             // ���� ������ ���
//	//				
//	//				node->parent->color = TreeColor::BLACK;
//	//				node->parent->parent->color = TreeColor::RED;
//	//				rotation_Left(node->parent->parent);
//	//				
//	//			}								 
//
//	//		}
//	//		else // �θ� ��ü�� Left�� ���  	
//	//		{
//	//			Node* Uncle = node->parent->parent->right;
//
//	//			if (Uncle->color == TreeColor::RED)
//	//			{
//	//				node->parent->parent->right->color = TreeColor::BLACK;
//	//				node->parent->color = TreeColor::BLACK;
//	//				node->parent->parent->color = TreeColor::RED;
//	//				node = node->parent->parent;
//	//			}
//	//			// ������ ���� ���
//	//			else 
//	//			{
//	//				
//	//				if (node == node->parent->right)	// ���� ������ ���
//	//				{
//	//					node = node->parent;
//	//					rotation_Left(node->parent);
//	//				}      
//	//				
//	//				node->parent->color = TreeColor::BLACK;
//	//				node->parent->parent->color = TreeColor::RED;
//	//				rotation_Right(node->parent->parent);
//	//				}
//	//			}								
//	//			
//	//		}
//
//	//	}
//
//	//	root->color = TreeColor::BLACK;
//	//}
//
//void rotation_Right(Node* n)			// �����̼� ��������
//{
//	Node* left = n->left;
//	n->left = left->right;
//
//	if (left->right != nil)
//	{
//		left->right->parent = n;
//	}
//
//	left->parent = n->parent;
//
//	if (n->parent == nil)
//	{
//		root = left;
//	}
//	else if (n == n->parent->right)
//	{
//		n->parent->right = left;
//	}
//	else
//	{
//		n->parent->left = left;
//	}
//
//	left->right = n;
//	n->parent = left;
//}
//
//void rotation_Left(Node* n)
//{
//	Node* right = n->right;
//	n->right = right->left;
//
//	if (right->left != nil)
//	{
//		right->left->parent = n;
//	}
//
//	right->parent = n->parent;
//
//	if (n->parent == nil)
//	{
//		root = right;
//	}
//	else if (n == n->parent->left)
//	{
//		n->parent->left = right;
//	}
//	else
//	{
//		n->parent->right = right;
//	}
//
//	right->left = n;
//	n->parent = right;
//}
//
//
//
//
//
//
//	void insert_Check(Node* node)
//	{
//		
//
//		while (node != root && node->parent->color == TreeColor::RED)
//		{
//			// �θ� ��ü�� Right�� ���
//			if (node->parent == node->parent->parent->right)		// �� �θ� �Һ����� ����
//			{
//				Node* Uncle = node->parent->parent->left;			// �׷� ������ ����
//
//				if (Uncle != nullptr && Uncle->color == TreeColor::RED) // ��.. ������ ���� ( 1�� )
//				{
//					Uncle->color = TreeColor::BLACK;
//					node->parent->color = TreeColor::BLACK;
//					node->parent->parent->color = TreeColor::RED;
//					node = node->parent->parent;						// �Ҿƹ��� ���� ��Ž��
//				}
//				// ������ ���̰ų� �������� �ʴ� ���
//				else
//				{
//					if (node == node->parent->left) // ���� ������ ���  (  )
//					{
//						node = node->parent;
//						rotation_Right(node);
//					}
//					// ���� ������ ���
//					node->parent->color = TreeColor::BLACK;
//					node->parent->parent->color = TreeColor::RED;
//					rotation_Left(node->parent->parent);
//				}
//			}
//			else // �θ� ��ü�� Left�� ���
//			{
//				Node* Uncle = node->parent->parent->right;				// �׷� �Һ��� ������ ����
//				
//				if (Uncle != nullptr && Uncle->color == TreeColor::RED)	 // 
//				{
//					Uncle->color = TreeColor::BLACK;
//					node->parent->color = TreeColor::BLACK;
//					node->parent->parent->color = TreeColor::RED;
//					node = node->parent->parent;
//				}
//				// ������ ���̰ų� �������� �ʴ� ���
//				else
//				{
//					if (node == node->parent->right) // ���� ������ ���
//					{
//						node = node->parent;
//						rotation_Left(node);
//					}
//					// ���� ������ ���
//					node->parent->color = TreeColor::BLACK;
//					node->parent->parent->color = TreeColor::RED;
//					rotation_Right(node->parent->parent);
//				}
//			}
//		}
//		root->color = TreeColor::BLACK;
//	}
//	
//	
//
//	Node* search(int value)
//	{
//		if (root == nil)
//		{
//			return nullptr;
//		}
//
//		Node* node = root;
//
//		while (node)
//		{
//			if (value == node->_Key)
//			{
//				return node;
//			}
//			if (value < node->_Key)
//			{
//				node = node->left;
//			}
//			else
//			{
//				node = node->right;
//			}
//		}
//
//		return nullptr;
//	}
//
//	void insertNode(int key)		
//	{
//		
//			Node* newNode = new Node();
//			newNode->_Key = key;
//
//
//			Node* node = root;
//			Node* parent = nil;
//
//			while (node != nil)
//			{
//				parent = node;
//				if (key < node->_Key)
//				{
//					node = node->left;
//				}
//				else
//				{
//					node = node->right;
//				}
//			}
//
//			newNode->parent = parent;
//
//			if (parent == nil)
//			{
//				root = newNode;
//			}
//			else if(key < parent->_Key)
//			{
//				parent->left = newNode;
//			}
//			else
//			{
//				parent->right = newNode;
//			}
//
//
//
//			newNode->left = nil;
//			newNode->right = nil;
//			newNode->color = TreeColor::RED;
//
//			insert_Check(newNode);
//		
//
//	}
//
//
//	void deleteTreeNode(Node* node) {
//		Node* deleteNode = node;
//
//		 /*�ݷ� 1. ���� ��带 ������ ���� �����ϴ�.*/
//		if (deleteNode == nil) { // nullptr üũ
//			return;
//		}
//
//		 //Case 1. �ڽ� ��尡 ���� ���
//		if (deleteNode->left == nullptr && deleteNode->right == nullptr) {
//			 //�θ� �ڽ� ���谡 ���� ��� ����, ����
//			if (deleteNode->parent) {
//				Node* parent = deleteNode->parent;
//
//				 //������ ��尡 �θ� ��� �������� �����̸�
//				if (parent->left == deleteNode) {
//					parent->left = nullptr;
//				}
//				else {
//					parent->right = nullptr;
//				}
//			}
//
//			delete(deleteNode);
//			return;
//		}
//
//		 //Case 2. �ڽ� ��尡 2�� ���� ���
//		if (deleteNode->left && deleteNode->right) {
//			deleteNode->_Key = next(deleteNode)->_Key;
//
//			deleteNode = next(deleteNode);
//
//			deleteTreeNode(deleteNode);
//
//			 //���� ����� next ���� ���� ������ �ٲٰ� �� ��带 �����ϸ� ������ �������ϴ�.
//			return;
//		}
//
//		 //Case 3. �ڽ� ��尡 �ϳ��� ���� ���
//		 //������� �Դٸ� �ڽ��� �� �� ���� ���� �� �� �����ϴ�. �ϳ��� �ִ� ����Դϴ�.
//
//		 //�ڽ� ��尡 �������� Ž��
//		Node* child = (deleteNode->left) ? deleteNode->left : deleteNode->right;
//
//		if (deleteNode->parent) { // �θ� ������, �θ� ���� �ڽİ� ������Ѿ� ��
//			if (deleteNode->parent->left == deleteNode) { // ������ ��尡 �θ� ���� �����̸�
//				deleteNode->parent->left = child;
//			}
//			else { // ������ ��尡 �θ� ���� �����̸�
//				deleteNode->parent->right = child;
//			}
//		}
//		if (child) { // �ڽ� ���� ���� �� �ۿ� ����, Case 3���� ������
//			child->parent = deleteNode->parent;
//		}
//		delete deleteNode;
//
//		return;
//	}   // ��
//
//
//	void Render(HDC hdc, HWND hWnd, Node* node, int left, int right, int depth)
//	{
//		if (node == nil)
//		{
//			return;
//		}
//
//		int middle = (left + right) / 2;
//		int rectHeight = 35;
//		int rectWidth = 50;
//
//		// �簢���� �׸���
//		HBRUSH hBrush;
//		if (node->color == TreeColor::BLACK)
//		{
//			hBrush = CreateSolidBrush(RGB(0, 0, 0));
//		}
//		else
//		{
//			hBrush = CreateSolidBrush(RGB(255, 0, 0));
//		}
//		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
//
//		Rectangle(hdc, middle - rectWidth / 2, depth * rectHeight, middle + rectWidth / 2, (depth + 1) * rectHeight);
//
//		SelectObject(hdc, oldBrush);
//		DeleteObject(hBrush);
//
//		// �簢�� �߾ӿ� _Key ���� �׸���
//		wchar_t buffer[10];
//		swprintf_s(buffer, L"%d", node->_Key);
//		int textX = middle - rectWidth / 4;  // �ؽ�Ʈ�� X ��ǥ (�簢�� �߾�)
//		int textY = depth * rectHeight + rectHeight / 4;  // �ؽ�Ʈ�� Y ��ǥ (�簢�� �߾�)
//		TextOutW(hdc, textX, textY, buffer, wcslen(buffer));
//
//		// �θ� ���� �����ϴ� �� �׸��� (�θ� ��尡 �ִ� ���)
//		if (node->parent != nil)
//		{
//			int parentMiddle = (left + right) / 2;
//			MoveToEx(hdc, middle, depth * rectHeight, NULL);
//			LineTo(hdc, (left + right) / 2, (depth - 1) * rectHeight + rectHeight);
//		}
//
//		// �ڽ� ����� ��ǥ ��� �� ���� �� �׸���
//		if (node->left != nil)
//		{
//			int childMiddle = (left + middle) / 2;
//			MoveToEx(hdc, middle, (depth + 1) * rectHeight, NULL);
//			LineTo(hdc, childMiddle, (depth + 1) * rectHeight + rectHeight / 2);
//			Render(hdc, hWnd, node->left, left, middle, depth + 1);
//		}
//
//		if (node->right != nil)
//		{
//			int childMiddle = (middle + right) / 2;
//			MoveToEx(hdc, middle, (depth + 1) * rectHeight, NULL);
//			LineTo(hdc, childMiddle, (depth + 1) * rectHeight + rectHeight / 2);
//			Render(hdc, hWnd, node->right, middle, right, depth + 1);
//		}
//	}
//
//	
//
//
//
//public:
//	Node* root = nullptr;
//
//	Node* nil = nullptr;
//};




#pragma once
#include <Windows.h>
#include <cstdio>
#include <cstring>

enum class TreeColor
{
    BLACK = 0,
    RED = 1
};

struct Node
{
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    int _Key = 0;
    TreeColor color = TreeColor::BLACK;
};





class RedBlackTree
{
public:
    RedBlackTree()
    {
        nil = new Node();
        nil->color = TreeColor::BLACK;
        root = nil;
    }


    //	 - Node N �� �������� ��ȸ��

    //	//			   N
    //
    //	//		   A       D
    //
    //	//		 B   C   E   F
    //
    //
    //	//				A
    //
    //	//	    	B       N
    //	
    //	//				 C     D
    //
    //	//					E    F
    //
    //	//	*/
    void rotation_Right(Node* n)
    {
        Node* left = n->left;
        n->left = left->right;
        if (left->right != nil)
            left->right->parent = n;
        left->parent = n->parent;
        if (n->parent == nil)
            root = left;
        else if (n == n->parent->right)
            n->parent->right = left;
        else
            n->parent->left = left;
        left->right = n;
        n->parent = left;
    }

    //		/*	���� ����Ʈ 1.
//										20
//									10		30
//										  25  40
//										24  26  50
//		*/			// �̷� �������� 20���� Next�� ���� ��,  Right�� ������ ������? 
//		// 30�� ���� ���� ���� 24�� ���� ����


//		/*
//										20
//									10		30
//										  25  40
//										24  26  50
//		// �̷� �������� 26�� ���� ����? �θ��� 25�� �ƴϰ� 30��
//		// 25�� �����ϸ� �ȵǴϱ�, �θ� Ÿ�� ���� 

    void rotation_Left(Node* n)
    {
        Node* right = n->right;
        n->right = right->left;
        if (right->left != nil)
            right->left->parent = n;
        right->parent = n->parent;
        if (n->parent == nil)
            root = right;
        else if (n == n->parent->left)
            n->parent->left = right;
        else
            n->parent->right = right;
        right->left = n;
        n->parent = right;
    }
    
    // ������ ����	// ���� ����� ������, 4�� ��Ģ
//		// 1. �θ� ����, ���� ����
//		// 
//		// 2. �θ� ����, ���� ��, ���� ����          / Ʈ���̾ޱ� ����  . �ᱹ Ʈ���̾ޱ��� ����Ʈ��
//		// 3. �θ� ����, ���� ��, ���� ����			/ ����Ʈ ����

    void insertNode(int key)
    {
        Node* newNode = new Node();
        newNode->_Key = key;
        newNode->left = nil;
        newNode->right = nil;
        newNode->color = TreeColor::RED;

        Node* parent = nil;
        Node* node = root;

        while (node != nil)
        {
            parent = node;
            if (newNode->_Key < node->_Key)
                node = node->left;
            else
                node = node->right;
        }

        newNode->parent = parent;
        if (parent == nil)
            root = newNode;
        else if (newNode->_Key < parent->_Key)
            parent->left = newNode;
        else
            parent->right = newNode;

        insertFix(newNode);
    }

    void insertFix(Node* node)
    {
        while (node != root && node->parent->color == TreeColor::RED)
        {
            if (node->parent == node->parent->parent->left)
            {
                Node* uncle = node->parent->parent->right;
                if (uncle != nullptr && uncle->color == TreeColor::RED)
                {
                    node->parent->color = TreeColor::BLACK;
                    uncle->color = TreeColor::BLACK;
                    node->parent->parent->color = TreeColor::RED;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->right)
                    {
                        node = node->parent;
                        rotation_Left(node);
                    }
                    node->parent->color = TreeColor::BLACK;
                    node->parent->parent->color = TreeColor::RED;
                    rotation_Right(node->parent->parent);
                }
            }
            else
            {
                Node* uncle = node->parent->parent->left;
                if (uncle != nullptr && uncle->color == TreeColor::RED)
                {
                    node->parent->color = TreeColor::BLACK;
                    uncle->color = TreeColor::BLACK;
                    node->parent->parent->color = TreeColor::RED;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->left)
                    {
                        node = node->parent;
                        rotation_Right(node);
                    }
                    node->parent->color = TreeColor::BLACK;
                    node->parent->parent->color = TreeColor::RED;
                    rotation_Left(node->parent->parent);
                }
            }
        }
        root->color = TreeColor::BLACK;
    }

    void deleteNode(int key)
    {
        Node* nodeToDelete = search(key);
        if (nodeToDelete == nil)
            return;

        Node* y = nodeToDelete;
        Node* x = nullptr;
        TreeColor yOriginalColor = y->color;

        if (nodeToDelete->left == nil)
        {
            x = nodeToDelete->right;
            transplant(nodeToDelete, nodeToDelete->right);
        }
        else if (nodeToDelete->right == nil)
        {
            x = nodeToDelete->left;
            transplant(nodeToDelete, nodeToDelete->left);
        }
        else
        {
            y = minNode(nodeToDelete->right);
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == nodeToDelete)
                x->parent = y;
            else
            {
                transplant(y, y->right);
                y->right = nodeToDelete->right;
                y->right->parent = y;
            }

            transplant(nodeToDelete, y);
            y->left = nodeToDelete->left;
            y->left->parent = y;
            y->color = nodeToDelete->color;
        }

        if (yOriginalColor == TreeColor::BLACK)
            deleteFix(x);
    }

    void deleteFix(Node* x)
    {
        while (x != root && x->color == TreeColor::BLACK)
        {
            if (x == x->parent->left)
            {
                Node* sibling = x->parent->right;
                if (sibling->color == TreeColor::RED)
                {
                    sibling->color = TreeColor::BLACK;
                    x->parent->color = TreeColor::RED;
                    rotation_Left(x->parent);
                    sibling = x->parent->right;
                }
                if (sibling->left->color == TreeColor::BLACK && sibling->right->color == TreeColor::BLACK)
                {
                    sibling->color = TreeColor::RED;
                    x = x->parent;
                }
                else
                {
                    if (sibling->right->color == TreeColor::BLACK)
                    {
                        sibling->left->color = TreeColor::BLACK;
                        sibling->color = TreeColor::RED;
                        rotation_Right(sibling);
                        sibling = x->parent->right;
                    }
                    sibling->color = x->parent->color;
                    x->parent->color = TreeColor::BLACK;
                    sibling->right->color = TreeColor::BLACK;
                    rotation_Left(x->parent);
                    x = root;
                }
            }
            else
            {
                Node* sibling = x->parent->left;
                if (sibling->color == TreeColor::RED)
                {
                    sibling->color = TreeColor::BLACK;
                    x->parent->color = TreeColor::RED;
                    rotation_Right(x->parent);
                    sibling = x->parent->left;
                }
                if (sibling->left->color == TreeColor::BLACK && sibling->right->color == TreeColor::BLACK)
                {
                    sibling->color = TreeColor::RED;
                    x = x->parent;
                }
                else
                {
                    if (sibling->left->color == TreeColor::BLACK)
                    {
                        sibling->right->color = TreeColor::BLACK;
                        sibling->color = TreeColor::RED;
                        rotation_Left(sibling);
                        sibling = x->parent->left;
                    }
                    sibling->color = x->parent->color;
                    x->parent->color = TreeColor::BLACK;
                    sibling->left->color = TreeColor::BLACK;
                    rotation_Right(x->parent);
                    x = root;
                }
            }
        }
        x->color = TreeColor::BLACK;
    }

    void transplant(Node* u, Node* v)
    {
        if (u->parent == nil)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    Node* minNode(Node* node)
    {
        while (node->left != nil)
            node = node->left;
        return node;
    }

    Node* search(int key)
    {
        Node* node = root;
        while (node != nil && node->_Key != key)
        {
            if (key < node->_Key)
                node = node->left;
            else
                node = node->right;
        }
        return node;
    }

    void Render(HDC hdc, HWND hWnd, Node* node, int left, int right, int depth)
    {
        if (node == nil)
            return;

        int middle = (left + right) / 2;
        int rectHeight = 35;
        int rectWidth = 50;

        HBRUSH hBrush;
        if (node->color == TreeColor::BLACK)
            hBrush = CreateSolidBrush(RGB(0, 0, 0));
        else
            hBrush = CreateSolidBrush(RGB(255, 0, 0));

        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        Rectangle(hdc, middle - rectWidth / 2, depth * rectHeight, middle + rectWidth / 2, (depth + 1) * rectHeight);
        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        wchar_t buffer[10];
        swprintf_s(buffer, L"%d", node->_Key);
        TextOutW(hdc, middle - rectWidth / 4, depth * rectHeight + rectHeight / 4, buffer, wcslen(buffer));

        if (node->left != nil)
        {
            int childMiddle = (left + middle) / 2;
            MoveToEx(hdc, middle, (depth + 1) * rectHeight, NULL);
            LineTo(hdc, childMiddle, (depth + 1) * rectHeight + rectHeight / 2);
            Render(hdc, hWnd, node->left, left, middle, depth + 1);
        }

        if (node->right != nil)
        {
            int childMiddle = (middle + right) / 2;
            MoveToEx(hdc, middle, (depth + 1) * rectHeight, NULL);
            LineTo(hdc, childMiddle, (depth + 1) * rectHeight + rectHeight / 2);
            Render(hdc, hWnd, node->right, middle, right, depth + 1);
        }
    }

public:
    Node* root;
    Node* nil;
};
