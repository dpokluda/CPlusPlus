#pragma once
#include <map>
#include <memory>
#include <string>

class Trie
{
private:
	struct TrieNode
	{
		std::map<char, std::unique_ptr<TrieNode>> children;
		bool isTerminalNode;

		TrieNode() : isTerminalNode(false) {}
	};

	std::unique_ptr<TrieNode> _root;

public:
	Trie() : _root(std::make_unique<TrieNode>()) {}

	void Insert(const std::string& word)
	{
		auto current = _root.get();
		for (char ch : word)
		{
			if (current->children.find(ch) == current->children.end())
			{
				current->children[ch] = std::make_unique<TrieNode>();
			}
			current = current->children[ch].get();
		}
		current->isTerminalNode = true;
	}

	bool Search(const std::string& word) const
	{
		auto current = _root.get();
		for (char ch : word)
		{
			if (current->children.find(ch) == current->children.end())
			{
				return false;
			}
			current = current->children[ch].get();
		}

		return current->isTerminalNode;
	}
};

