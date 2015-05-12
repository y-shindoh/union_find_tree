/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @brief	union_find_tree.hppの動作確認用コマンド
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstdio>
#include "union_find_tree.hpp"

int
main()
{
	ys::UnionFindTree<unsigned, 16>* tree = new ys::UnionFindTree<unsigned, 16>();

	unsigned unite[][2] = {{0, 3}, {3, 6}, {9, 0}, {2, 4}, {5, 4}};
	for (size_t i(0); i < sizeof(unite)/sizeof(unite[0]); ++i) {
		std::printf("U: %u <=> %u\n", unite[i][0], unite[i][1]);
		tree->unite(unite[i][0], unite[i][1]);
	}

	unsigned check[][2] = {{6, 9}, {3, 5}, {2, 5}};
	bool flag;
	for (size_t i(0); i < sizeof(check)/sizeof(check[0]); ++i) {
		flag = tree->same(check[i][0], check[i][1]);
		if (flag) {
			std::printf("C: %u === %u\n", check[i][0], check[i][1]);
		}
		else {
			std::printf("C: %u !== %u\n", check[i][0], check[i][1]);
		}
	}

	delete tree;

	return 0;
}
