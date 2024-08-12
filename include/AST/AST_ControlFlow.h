//
// Created by kiran on 5/21/24.
//

#ifndef KL_AST_CONTROLFLOW_H
#define KL_AST_CONTROLFLOW_H

#include "AST_Statements.h"

class ASTControLFlowIf : ASTStmt {
  unique_ptr<ASTExpr> condition;
  unique_ptr<ASTBlock> then_block;
  unique_ptr<ASTBlock> else_block;

  [[nodiscard]] ASTNodeType get_AST_type() const override {
    return ControlFlowIf;
  }

  KLCodeGenResult *accept(KLCodeGenVisitor *v) override { return v->visit(this); }

  ASTControLFlowIf(unique_ptr<ASTExpr> condition,
                   unique_ptr<ASTBlock> then_block,
                   unique_ptr<ASTBlock> else_block)
      : condition(std::move(condition)), then_block(std::move(then_block)),
        else_block(std::move(else_block)) {}
};

#endif //KL_AST_CONTROLFLOW_H
