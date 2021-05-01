using System;
using System.Collections.Generic;
using System.Text;

namespace BST
{
    public class Node<TId, T> where TId : IComparable<TId>
    {
        private TId _id;
        public TId Id { get { return _id; } }
        private T _data;
        public T Data { get { return _data; } }
        private Node<TId, T> _parent;
        public Node<TId, T> Parent { get { return _parent; } }
        private Node<TId, T> _left;
        public Node<TId, T> Left { get { return _left; } }
        private Node<TId, T> _right;
        public Node<TId, T> Right { get { return _right; } }

        public Node(TId id, T data)
        {
            _id = id;
            _data = data;
        }
    }
}
