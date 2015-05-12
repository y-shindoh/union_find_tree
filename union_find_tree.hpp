/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	union_find_tree.hpp
 * @brief	union find treeのテンプレート
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	http://algoogle.hadrori.jp/algorithm/union-find.html を参考に実装した。
 * @note	経路圧縮の実装を含めていない。
 */

#include <cstddef>
#include <cassert>
#include <vector>

namespace ys
{
	/**
	 * @class	union find treeのテンプレート
	 * @note	テンプレートの型 @a TYPE には符号なし整数を指定すること。
	 * @note	テンプレートの整数 @a N には集合の要素数を指定すること。
	 */
	template<typename TYPE, size_t N>
	class UnionFindTree
	{
	private:

		std::vector<TYPE> parent_;	///< 代表のインデックス
		std::vector<TYPE> rank_;	///< ランク

		/**
		 * 代表のインデックスの取得
		 */
		size_t
		find(size_t i) const
			{
				assert(i < N);

				size_t j;

				while ('-') {
					j = (size_t)parent_[i];
					if (i == j) return i;
					i = j;
				}
			}

	public:

		/**
		 * コンストラクタ
		 */
		UnionFindTree()
			{
				parent_.resize(N);
				rank_.resize(N, (TYPE)1);

				for (size_t i(0); i < N; ++i) {
					parent_[i] = (TYPE)i;
				}
			}

		/**
		 * 2つのグループを統合
		 * @param[in]	i	インデックスその1
		 * @param[in]	j	インデックスその2
		 */
		void
		unite(size_t i,
			  size_t j) {
			i = find(i);
			j = find(j);
			if (i == j) return;

			if (rank_[i] < rank_[j]) {
				parent_[i] = (TYPE)j;
			}
			else {
				parent_[j] = (TYPE)i;
				if (rank_[i] == rank_[j]) rank_[i]++;
			}
		}

		/**
		 * 2つのインデックスが同一グループに所属しているか確認
		 * @param[in]	i	インデックスその1
		 * @param[in]	j	インデックスその2
		 * @return	true: 所属している, false: 所属していない
		 */
		bool
		same(size_t i,
			 size_t j) const
			{
				return find(i) == find(j);
			}
	};
};
