#include "CodeFromAST/CodeExpander.h"

CodeNode* CodeExpander::Expand(CodeNode* root) {
   root->Visit(this);
   return PopResult();
}

void CodeExpander::PushResult(CodeNode* codeNode) {
   m_result.push_back(codeNode);
}

CodeNode* CodeExpander::PopResult() {
   CodeNode* result = m_result.back();
   m_result.pop_back();
   return result;
}



void CodeExpander::VisitExprFromInt(ExprFromInt* exprFromInt) {}

void CodeExpander::VisitExprFromBool(ExprFromBool* exprFromBool) {}

void CodeExpander::VisitExprFromVariable(ExprFromVariable* exprFromVariable) {}

void CodeExpander::VisitParenthesizedExpr(ParenthesizedExpr* parenthesizedExpr) {}

void CodeExpander::VisitMinus(Minus* minus) {}

void CodeExpander::VisitNegation(Negation* negation) {}

void CodeExpander::VisitAddition(Addition * addition) {}

void CodeExpander::VisitMultiplication(Multiplication * multiplication) {}

void CodeExpander::VisitSubstraction(Substraction * substraction) {}

void CodeExpander::VisitEuclidianDivision(EuclidianDivision * euclDiv) {}

void CodeExpander::VisitModulus(Modulus * modulus) {}

void CodeExpander::VisitAnd(And * andNode) {}

void CodeExpander::VisitOr(Or * orNode) {}

void CodeExpander::VisitBloc(Bloc* bloc) {
   int nbCodeNodes = bloc->GetNbCodeNodes();
   CodeNode** codeNode = new CodeNode*[nbCodeNodes];
   for(int iCodeNode = 0; iCodeNode < nbCodeNodes; iCodeNode++) {
      codeNode[iCodeNode] = Expand(bloc->GetCodeNode(iCodeNode));
   }
   PushResult(new Bloc(codeNode,nbCodeNodes));
}

void CodeExpander::VisitIf(If * ifNode) {}

void CodeExpander::VisitElseIf(ElseIf * elseIfNode) {}

void CodeExpander::VisitElse(Else * elseNode) {}

void CodeExpander::VisitDeclaration(Declaration * decl) {}

void CodeExpander::VisitRange(Range * range) {}

void CodeExpander::VisitFor(For * forNode) {}

void CodeExpander::VisitFunction(Function * function) {}

void CodeExpander::VisitSignature(Signature * signature) {}

void CodeExpander::VisitFunctionDeclaration(FunctionDeclaration * functionDecl) {}

void CodeExpander::VisitIncludeLib(IncludeLib* includeLib) {}

void CodeExpander::VisitPrintableFromString(PrintableFromString * printStr) {}

void CodeExpander::VisitPrintableFromExpression(PrintableFromExpression * printExpr) {}

void CodeExpander::VisitPrint(Print * print) {}

void CodeExpander::VisitType(Type * type) {}

void CodeExpander::VisitVariable(Variable* variable) {}

void CodeExpander::VisitWhile(While* whileNode) {}
   
void CodeExpander::VisitMain(Main* mainNode) {}