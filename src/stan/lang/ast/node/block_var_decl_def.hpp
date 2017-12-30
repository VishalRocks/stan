#ifndef STAN_LANG_AST_NODE_BLOCK_VAR_DECL_DEF_HPP
#define STAN_LANG_AST_NODE_BLOCK_VAR_DECL_DEF_HPP

#include <stan/lang/ast.hpp>
#include <string>
#include <vector>

namespace stan {
  namespace lang {

    block_var_decl::block_var_decl(const block_var_decl_t& x) : var_decl_(x) { }

    block_var_decl::block_var_decl() : var_decl_(nil()) { }

    block_var_decl::block_var_decl(const nil& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const int_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const double_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const vector_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const row_vector_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const matrix_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const unit_vector_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const simplex_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const ordered_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const positive_ordered_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const cholesky_factor_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const cholesky_corr_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const cov_matrix_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const corr_matrix_block_var_decl& x) : var_decl_(x) { }

    block_var_decl::block_var_decl(const array_block_var_decl& x) : var_decl_(x) { }

    std::string block_var_decl::name() const {
      var_decl_name_vis vis;
      return boost::apply_visitor(vis, var_decl_);
    }

    bare_expr_type block_var_decl::type() const {
      var_decl_type_vis vis;
      return boost::apply_visitor(vis, var_decl_);
    }

    bool block_var_decl::has_def() const {
      var_decl_has_def_vis vis;
      return boost::apply_visitor(vis, var_decl_);
    }

    expression block_var_decl::def() const {
      var_decl_def_vis vis;
      return boost::apply_visitor(vis, var_decl_);
    }

    // std::vector<expression> block_var_decl::size() const {
    //   return boost::apply_visitor(var_decl_size_vis(), var_decl_);
    // }
    
    // bool block_var_decl::has_lower() const {
    //   var_decl_has_lower_vis vis;
    //   return boost::apply_visitor(vis, var_decl_);
    // }

    // expression block_var_decl::lower() const {
    //   var_decl_lower_vis vis;
    //   return boost::apply_visitor(vis, var_decl_);
    // }

    // bool block_var_decl::has_upper() const {
    //   var_decl_has_upper_vis vis;
    //   return boost::apply_visitor(vis, var_decl_);
    // }

    // expression block_var_decl::upper() const {
    //   var_decl_upper_vis vis;
    //   return boost::apply_visitor(vis, var_decl_);
    // }

  }
}
#endif