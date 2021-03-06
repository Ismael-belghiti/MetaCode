#ifndef INTERFACE_TYPE_H
#define INTERFACE_TYPE_H

#include <string>

class AbstractVisitor;

class AbstractTypeTransformer;
class AbstractVariableTransformer;
class AbstractExpressionTransformer;
class AbstractStatementTransformer;

// Constructions

class IType {
public:
   virtual std::string GetName() = 0;

   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;
   
   virtual IType* TransformType(AbstractTypeTransformer* transformer) = 0;
};

class IVariable {
public:
   virtual IType* GetType() = 0;

   virtual std::string GetName() = 0;

   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;

   virtual IVariable* TransformVariable(AbstractVariableTransformer* transformer) = 0;
};

class IExpression {
public:
   virtual IType* GetType() = 0;
   
   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;  

   virtual IExpression* TransformExpression(AbstractExpressionTransformer* transformer) = 0;
};

class IStatement {
public:
   virtual void PrintDebug(int level = 0) = 0;

   virtual void Visit(AbstractVisitor* visitor) = 0;

   virtual IStatement* TransformStatement(AbstractStatementTransformer* transformer) = 0;
};



// Intermediates Constructions, used for convenience

class IBloc {
public:
   virtual int GetNbStatements() = 0;

   virtual IStatement* GetStatement(int iStatement) = 0;

   virtual void PrintDebug(int level = 0) = 0;
};

class IRange {
public:
   virtual bool IsIncreasing() = 0;

   virtual IExpression* GetStart() = 0;

   virtual IExpression* GetExcludedEnd() = 0;

   virtual bool IncludedEndIsDefined() = 0;

   virtual IExpression* GetIncludedEnd() = 0;

   virtual void PrintDebug(int level = 0) = 0;
};

class IPrintable {
public:
   virtual bool IsExpression() = 0;

   virtual std::string GetString() = 0;

   virtual IExpression* GetExpression() = 0;

   virtual void PrintDebug(int level = 0) = 0;
};


#endif 
