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
//	Node* minNode(Node* node)		// 말 그대로 Node 기준 가장 작은 값을 left left left
//	{
//		while (node->left != nil)
//		{
//			node = node->left;
//		}
//
//		return node;
//	}
//
//	Node* maxNode(Node* node)		// 말 그대로 Node 기준 가장 큰 값을 right right ...
//	{
//		while (node->right != nil)
//		{
//			node = node->right;
//		}
//
//		return node;
//	}
//
//	Node* next(Node* node)	// Node 기준 다음 값은 뭘가? 
//	{
//		if (node->right != nil)			// Right가 있다면 
//			// 이진 트리 구조
//		{
//			return minNode(node->right);		// Right의 제일 좌측에 있는 값이 그 값임.
//		}
//

//
//
////  Right가 없어서 부모를 타고 가려고 함. 근데 부모가 다음 값이 아닐 수 있음
////  Parent를 타고 갔는데, Parent가 또 Parent의 우측에 있는 경우를 없애려고함
////  즉 노드가 부모의 우측 값으로 가지고 있으면 안됨. 다음 값이 아님.
//
//		Node* parent = node->parent;
//		while (parent != nil && node == parent->right)	// node 가 parent의 right에 있는 경우에는 계속
//		{
//			node = parent;
//			parent = parent->parent;
//		}
//
// 

//
//
//		return parent;	// 본인이 아닌 부모 값이 다음 값.
//	}
//
//	//void rotation_Right(Node* n)				원본 로테이션
//	//{
//	//	// 1. N 의 왼쪽 자식의 우측 값을 N이 가짐, n은 왼쪽 자식의 우측 값으로 들어감
//
//	//		// 먼저 N의 Left 보관
//	//	Node* Origin_Left = n->left;
//
//	//		// Left를 보관했으니, n의 좌측 값을 Origin_left 의 우측 값으로 바꿈
//	//	n->left = Origin_Left->right;
//	//	Origin_Left->right->parent = n;
//	//	
//	//	// 2. N 의 원래 왼쪽 자식을 N의 자리로 올림
//	//		
//	//	Origin_Left->right = n;
//	//	Origin_Left->parent = n->parent;
//	//	n->parent = Origin_Left;
//	//	
//

//	//}
//
//	/*void rotation_Left(Node* n)		// 원본 로테이션
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
//	//	// 삽입의 문제	// 내가 레드로 시작함, 4번 법칙
//	//	// 1. 부모 레드, 삼촌 레드
//	//	// 2. 부모 레드, 삼촌 블랙, 내가 왼쪽
//	//	// 3. 부모 레드
//
//	//	while (node->parent->color == TreeColor::RED)
//	//	{
//	//		// 부모 자체가 Right인 경우
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
//	//			// 삼촌이 블랙인 경우
//	//			else
//	//			{
//	//				if (node == node->parent->left)	// 내가 우측인 경우
//	//				{
//	//					node = node->parent;
//	//					rotation_Right(node->parent);
//	//				}
//	//				                             // 내가 좌측인 경우
//	//				
//	//				node->parent->color = TreeColor::BLACK;
//	//				node->parent->parent->color = TreeColor::RED;
//	//				rotation_Left(node->parent->parent);
//	//				
//	//			}								 
//
//	//		}
//	//		else // 부모 자체가 Left인 경우  	
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
//	//			// 삼촌이 블랙인 경우
//	//			else 
//	//			{
//	//				
//	//				if (node == node->parent->right)	// 내가 우측인 경우
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
//void rotation_Right(Node* n)			// 로테이션 오리지널
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
//			// 부모 자체가 Right인 경우
//			if (node->parent == node->parent->parent->right)		// 내 부모가 할부지의 우측
//			{
//				Node* Uncle = node->parent->parent->left;			// 그럼 삼촌은 왼쪽
//
//				if (Uncle != nullptr && Uncle->color == TreeColor::RED) // 자.. 삼촌이 레드 ( 1번 )
//				{
//					Uncle->color = TreeColor::BLACK;
//					node->parent->color = TreeColor::BLACK;
//					node->parent->parent->color = TreeColor::RED;
//					node = node->parent->parent;						// 할아버지 기준 재탐색
//				}
//				// 삼촌이 블랙이거나 존재하지 않는 경우
//				else
//				{
//					if (node == node->parent->left) // 내가 좌측인 경우  (  )
//					{
//						node = node->parent;
//						rotation_Right(node);
//					}
//					// 내가 우측인 경우
//					node->parent->color = TreeColor::BLACK;
//					node->parent->parent->color = TreeColor::RED;
//					rotation_Left(node->parent->parent);
//				}
//			}
//			else // 부모 자체가 Left인 경우
//			{
//				Node* Uncle = node->parent->parent->right;				// 그럼 할부지 우측이 삼촌
//				
//				if (Uncle != nullptr && Uncle->color == TreeColor::RED)	 // 
//				{
//					Uncle->color = TreeColor::BLACK;
//					node->parent->color = TreeColor::BLACK;
//					node->parent->parent->color = TreeColor::RED;
//					node = node->parent->parent;
//				}
//				// 삼촌이 블랙이거나 존재하지 않는 경우
//				else
//				{
//					if (node == node->parent->right) // 내가 우측인 경우
//					{
//						node = node->parent;
//						rotation_Left(node);
//					}
//					// 내가 좌측인 경우
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
//		 /*반례 1. 없는 노드를 삭제할 수는 없습니다.*/
//		if (deleteNode == nil) { // nullptr 체크
//			return;
//		}
//
//		 //Case 1. 자식 노드가 없을 경우
//		if (deleteNode->left == nullptr && deleteNode->right == nullptr) {
//			 //부모 자식 관계가 있을 경우 끊고, 삭제
//			if (deleteNode->parent) {
//				Node* parent = deleteNode->parent;
//
//				 //삭제할 노드가 부모 노드 기준으로 좌측이면
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
//		 //Case 2. 자식 노드가 2개 있을 경우
//		if (deleteNode->left && deleteNode->right) {
//			deleteNode->_Key = next(deleteNode)->_Key;
//
//			deleteNode = next(deleteNode);
//
//			deleteTreeNode(deleteNode);
//
//			 //현재 노드의 next 값을 다음 값으로 바꾸고 그 노드를 삭제하면 균형이 맞춰집니다.
//			return;
//		}
//
//		 //Case 3. 자식 노드가 하나만 있을 경우
//		 //여기까지 왔다면 자식이 둘 다 없는 경우는 될 수 없습니다. 하나만 있는 경우입니다.
//
//		 //자식 노드가 무엇인지 탐색
//		Node* child = (deleteNode->left) ? deleteNode->left : deleteNode->right;
//
//		if (deleteNode->parent) { // 부모가 있으면, 부모 또한 자식과 연결시켜야 함
//			if (deleteNode->parent->left == deleteNode) { // 삭제할 노드가 부모 기준 좌측이면
//				deleteNode->parent->left = child;
//			}
//			else { // 삭제할 노드가 부모 기준 우측이면
//				deleteNode->parent->right = child;
//			}
//		}
//		if (child) { // 자식 노드는 있을 수 밖에 없음, Case 3까지 왔으면
//			child->parent = deleteNode->parent;
//		}
//		delete deleteNode;
//
//		return;
//	}   // 굳
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
//		// 사각형을 그리기
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
//		// 사각형 중앙에 _Key 값을 그리기
//		wchar_t buffer[10];
//		swprintf_s(buffer, L"%d", node->_Key);
//		int textX = middle - rectWidth / 4;  // 텍스트의 X 좌표 (사각형 중앙)
//		int textY = depth * rectHeight + rectHeight / 4;  // 텍스트의 Y 좌표 (사각형 중앙)
//		TextOutW(hdc, textX, textY, buffer, wcslen(buffer));
//
//		// 부모 노드와 연결하는 선 그리기 (부모 노드가 있는 경우)
//		if (node->parent != nil)
//		{
//			int parentMiddle = (left + right) / 2;
//			MoveToEx(hdc, middle, depth * rectHeight, NULL);
//			LineTo(hdc, (left + right) / 2, (depth - 1) * rectHeight + rectHeight);
//		}
//
//		// 자식 노드의 좌표 계산 및 연결 선 그리기
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


    //	 - Node N 을 기준으로 우회전

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

    //		/*	생각 포인트 1.
//										20
//									10		30
//										  25  40
//										24  26  50
//		*/			// 이런 구조에서 20기준 Next를 구할 때,  Right를 가지고 있으면? 
//		// 30의 제일 좌측 값인 24가 다음 값임


//		/*
//										20
//									10		30
//										  25  40
//										24  26  50
//		// 이런 구조에서 26의 다음 값은? 부모인 25가 아니고 30임
//		// 25를 리턴하면 안되니까, 부모를 타고 가서 

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
    
    // 삽입의 문제	// 내가 레드로 시작함, 4번 법칙
//		// 1. 부모 레드, 삼촌 레드
//		// 
//		// 2. 부모 레드, 삼촌 블랙, 내가 우측          / 트라이앵글 구조  . 결국 트라이앵글은 리스트로
//		// 3. 부모 레드, 삼촌 블랙, 내가 왼쪽			/ 리스트 구조

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
