#include "CodeFromAST/CodeExpander.h"
#include "CodeFromAST/EmptyVisitor.h"


class ExprFromIntExpander : public EmptyVisitor {
public:
   ExprFromIntExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }
  
   virtual void VisitExprFromInt(ExprFromInt* exprFromInt) {
      m_result = new ExprFromInt(exprFromInt->GetValue());
   }

   ExprFromInt* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   ExprFromInt* m_result;
};

class ExpressionExpander : public EmptyVisitor {
public:
   ExpressionExpander(CodeExpander* codeExpander) {
      m_codeExpander = codeExpander;
   }

   virtual void VisitExprFromInt(ExprFromInt* exprFromInt) {
      m_result = m_codeExpander->ExpandExprFromInt(exprFromInt);
   }

   virtual void VisitExprFromBool(ExprFromBool* exprFromBool) {

   }

   virtual void VisitExprFromVariable(ExprFromVariable* exprFromVariable) {
      
   }

   virtual void VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {
      Expression* expr =
	 m_codeExpander->ExpandExpression(parenthesizedExpr->GetExpression());
      m_result = new ParenthesizedExpr(expr);
   }

   virtual void VisitMinus(Minus* minus) {
      Expression* expr =
	 m_codeExpander->ExpandExpression(minus->GetExpression());
      m_result = new Minus(expr);
   }

   virtual void VisitNegation(Negation* negation) {
      Expression* expr =
	 m_codeExpander->ExpandExpression(negation->GetExpression());
      m_result = new Negation(expr);
   }

   virtual void VisitAddition(Addition* add) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(add->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(add->GetRightExpr());
      m_result = new Addition(left,right);
   }

   virtual void VisitMultiplication(Multiplication * multiplication) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(multiplication->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(multiplication->GetRightExpr());
      m_result = new Multiplication(left,right);
   }

   virtual void VisitSubstraction(Substraction * substraction) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(substraction->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(substraction->GetRightExpr());
      m_result = new Substraction(left,right);
   }

   virtual void VisitEuclidianDivision(EuclidianDivision * euclDiv) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(euclDiv->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(euclDiv->GetRightExpr());
      m_result = new EuclidianDivision(left,right);
   }

   virtual void VisitModulus(Modulus * modulus) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(modulus->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(modulus->GetRightExpr());
      m_result = new Modulus(left,right);
   }

   virtual void VisitAnd(And * andNode) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(andNode->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(andNode->GetRightExpr());
      m_result = new And(left,right);
   }

   virtual void VisitOr(Or * orNode) {
      Expression* left = 
	 m_codeExpander->ExpandExpression(orNode->GetLeftExpr());
      Expression* right =
	 m_codeExpander->ExpandExpression(orNode->GetRightExpr());
      m_result = new Or(left,right);
   }

   // Warning : treat them all !

   Expression* GetResult() {
      return m_result;
   };

private:
   CodeExpander* m_codeExpander;
   Expression* m_result;
};

Expression* CodeExpander::ExpandExpression(Expression* expr) {
   ExpressionExpander* exprExpander = new ExpressionExpander(this);
   expr->Visit(exprExpander);
   Expression* result = exprExpander->GetResult();
   delete exprExpander;
   return result;
}

ExprFromInt* CodeExpander::ExpandExprFromInt(ExprFromInt* exprFromInt) {
   ExprFromIntExpander* exprExpander = new ExprFromIntExpander(this);
   exprFromInt->Visit(exprExpander);
   ExprFromInt* result = exprExpander->GetResult();
   delete exprExpander;
   return result;
}


