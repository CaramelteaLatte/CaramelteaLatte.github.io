## 2 Relation model

### 2.1 数据库模式，数据库实例

类比参数和参数的实际值

### 2.2 码

#### 2.2.1 Superkey 超码

a. 一个属性或多个属性的集合

b. superkey的组合能让我们唯一地标识一个元组，能够限制两个关系不会完全相同

#### 2.2.2 Candidate key 候选码

a. 如果 K 是一个超码，那么 K 的任意一个超集都是超码

b. 这样的最小超码成为候选码，一个 tuple 对应的候选码可以有很多个/种

c. {ID} 和 {dept_name} 都是候选码，但是 {ID, dept_name} 不是候选码

#### 2.2.3 Primary key 主码

a. 被数据库设计者选中的在一个 relation 中的候选码。

b. 主码的选择受限制，不能重复，选择值极少变化的属性，如人名会重复但身份证号不重复

#### 2.2.4 Foreign key 外码

a. 关系 R<sub>1</sub> 中包含属性 X，属性 X 是关系 R<sub>2</sub> 的主码，则属性 X 也是关系 R<sub>2</sub> 的外码。

b. R<sub>1</sub> 称为外码依赖的参照关系 referencing relation，R<sub>2</sub> 称为外码依赖的被参照关系 referenced relation。

