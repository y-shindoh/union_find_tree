/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	union_find_tree.hpp
 * @brief	union find treeのテンプレート
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	http://www.slideshare.net/iwiwi/ss-3578491 と
			http://algoogle.hadrori.jp/algorithm/union-find.html を参考に実装した。
 */

#ifndef	__UNION_FIND_TREE_HPP__
#define	__UNION_FIND_TREE_HPP__ "union_find_tree.hpp"

#if	!defined(__cplusplus) || __cplusplus < 201103L
#error	This library requires a C++11 compiler.
#endif

#include <cassert>
#include <vector>
#include <utility>

//#define	__UNION_FIND_TREE_WITH_SIZE__	1

namespace ys
{
	/**
	 * @class	union find treeのテンプレート
	 * @note	テンプレートの型 @a TYPE には符号あり整数を指定すること。
	 */
	template<typename TYPE>
	class UnionFindTree
	{
	private:

		std::vector<TYPE> data_;	///< 代表のインデックス or ランク
#ifdef	__UNION_FIND_TREE_WITH_SIZE__
		std::vector<size_t> size_;	///< グループの大きさ
#endif	// __UNION_FIND_TREE_WITH_SIZE__

		/**
		 * グループ代表のインデックスの取得
		 * @param[in]	i	インデックス
		 * @return	グループ代表のインデックス
		 */
		size_t
		find(size_t i)
			{
				assert(i < data_.size());

				if (data_[i] < (TYPE)0) return i;

				data_[i] = (TYPE)find(data_[i]);
				return (size_t)data_[i];
			}

	public:

		/**
		 * コンストラクタ
		 */
		UnionFindTree(size_t n)
#ifdef	__UNION_FIND_TREE_WITH_SIZE__
			: data_(n, (TYPE)-1), size_(n, (TYPE)1)
#else	// __UNION_FIND_TREE_WITH_SIZE__
			: data_(n, (TYPE)-1)
#endif	// __UNION_FIND_TREE_WITH_SIZE__
			{
				;
			}

		/**
		 * コピー・コンストラクタ (使用禁止)
		 */
		UnionFindTree(const UnionFindTree<TYPE>&) = delete;

		/**
		 * 代入演算子 (使用禁止)
		 */
		UnionFindTree&
		operator =(const UnionFindTree<TYPE>&) = delete;

		/**
		 * デストラクタ
		 */
		virtual
		~UnionFindTree()
			{
				;
			}

		/**
		 * 2つのグループを統合
		 * @param[in]	i	インデックスその1
		 * @param[in]	j	インデックスその2
		 */
		void
		unite(size_t i,
			  size_t j)
			{
				assert(i < data_.size());
				assert(j < data_.size());

				i = find(i);
				j = find(j);
				if (i == j) return;

				if (data_[i] > data_[j]) std::swap<size_t>(i, j);
				data_[i] -= (data_[i] == data_[j]);
				data_[j] = (TYPE)i;
#ifdef	__UNION_FIND_TREE_WITH_SIZE__
				size_[i] += size_[j];
#endif	// __UNION_FIND_TREE_WITH_SIZE__
			}

		/**
		 * 2つのインデックスが同一グループに所属しているか確認
		 * @param[in]	i	インデックスその1
		 * @param[in]	j	インデックスその2
		 * @return	true: 所属している, false: 所属していない
		 */
		bool
		same(size_t i,
			 size_t j)
			{
				assert(i < data_.size());
				assert(j < data_.size());

				return find(i) == find(j);
			}

#ifdef	__UNION_FIND_TREE_WITH_SIZE__
		/**
		 * グループの大きさを取得
		 * @param[in]	i	インデックス
		 * @return	グループの大きさ
		 */
		TYPE
		size(size_t i)
			{
				assert(i < data_.size());

				i = find(i);
				return size_[i];
			}
#endif	// __UNION_FIND_TREE_WITH_SIZE__
	};
};

#endif	// __UNION_FIND_TREE_HPP__
