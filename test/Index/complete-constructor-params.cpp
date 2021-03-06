// Note: the run lines follow their respective tests, since line/column
// matter in this test.

template<class T>
struct S {
  template<class U>
  S(T, U, U) {}
};

int main() {
  S<int>(42, 42, 42);
  S<int>(42, 42, 42);
  S<int> s(42, 42, 42);

  S<int>(42, 42, 42,);
  S<int> z(42, 42, 42,);
}

// RUN: c-index-test -code-completion-at=%s:11:10 %s | FileCheck -check-prefix=CHECK-CC1 %s
// CHECK-CC1: OverloadCandidate:{Text S}{LeftParen (}{CurrentParameter const S<int> &}{RightParen )} (1)
// CHECK-CC1: OverloadCandidate:{Text S}{LeftParen (}{CurrentParameter int}{Comma , }{Text U}{Comma , }{Text U}{RightParen )} (1)
// CHECK-CC1: Completion contexts:
// CHECK-CC1-NEXT: Any type
// CHECK-CC1-NEXT: Any value
// CHECK-CC1-NEXT: Enum tag
// CHECK-CC1-NEXT: Union tag
// CHECK-CC1-NEXT: Struct tag
// CHECK-CC1-NEXT: Class name
// CHECK-CC1-NEXT: Nested name specifier
// CHECK-CC1-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:12:10 %s | FileCheck -check-prefix=CHECK-CC2 %s
// CHECK-CC2: OverloadCandidate:{Text S}{LeftParen (}{CurrentParameter const S<int> &}{RightParen )} (1)
// CHECK-CC2: OverloadCandidate:{Text S}{LeftParen (}{CurrentParameter int}{Comma , }{Text U}{Comma , }{Text U}{RightParen )} (1)
// CHECK-CC2: Completion contexts:
// CHECK-CC2-NEXT: Any type
// CHECK-CC2-NEXT: Any value
// CHECK-CC2-NEXT: Enum tag
// CHECK-CC2-NEXT: Union tag
// CHECK-CC2-NEXT: Struct tag
// CHECK-CC2-NEXT: Class name
// CHECK-CC2-NEXT: Nested name specifier
// CHECK-CC2-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:12:13 %s | FileCheck -check-prefix=CHECK-CC3 %s
// CHECK-CC3: OverloadCandidate:{Text S}{LeftParen (}{Text int}{Comma , }{CurrentParameter U}{Comma , }{Text U}{RightParen )} (1)
// CHECK-CC3: Completion contexts:
// CHECK-CC3-NEXT: Any type
// CHECK-CC3-NEXT: Any value
// CHECK-CC3-NEXT: Enum tag
// CHECK-CC3-NEXT: Union tag
// CHECK-CC3-NEXT: Struct tag
// CHECK-CC3-NEXT: Class name
// CHECK-CC3-NEXT: Nested name specifier
// CHECK-CC3-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:12:17 %s | FileCheck -check-prefix=CHECK-CC4 %s
// CHECK-CC4: OverloadCandidate:{Text S}{LeftParen (}{Text int}{Comma , }{Text int}{Comma , }{CurrentParameter int}{RightParen )} (1)
// CHECK-CC4: Completion contexts:
// CHECK-CC4-NEXT: Any type
// CHECK-CC4-NEXT: Any value
// CHECK-CC4-NEXT: Enum tag
// CHECK-CC4-NEXT: Union tag
// CHECK-CC4-NEXT: Struct tag
// CHECK-CC4-NEXT: Class name
// CHECK-CC4-NEXT: Nested name specifier
// CHECK-CC4-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:13:12 %s | FileCheck -check-prefix=CHECK-CC5 %s
// CHECK-CC5: OverloadCandidate:{Text S}{LeftParen (}{CurrentParameter const S<int> &}{RightParen )} (1)
// CHECK-CC5: OverloadCandidate:{Text S}{LeftParen (}{CurrentParameter int}{Comma , }{Text U}{Comma , }{Text U}{RightParen )} (1)
// CHECK-CC5: Completion contexts:
// CHECK-CC5-NEXT: Any type
// CHECK-CC5-NEXT: Any value
// CHECK-CC5-NEXT: Enum tag
// CHECK-CC5-NEXT: Union tag
// CHECK-CC5-NEXT: Struct tag
// CHECK-CC5-NEXT: Class name
// CHECK-CC5-NEXT: Nested name specifier
// CHECK-CC5-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:13:15 %s | FileCheck -check-prefix=CHECK-CC6 %s
// CHECK-CC6: OverloadCandidate:{Text S}{LeftParen (}{Text int}{Comma , }{CurrentParameter U}{Comma , }{Text U}{RightParen )} (1)
// CHECK-CC6: Completion contexts:
// CHECK-CC6-NEXT: Any type
// CHECK-CC6-NEXT: Any value
// CHECK-CC6-NEXT: Enum tag
// CHECK-CC6-NEXT: Union tag
// CHECK-CC6-NEXT: Struct tag
// CHECK-CC6-NEXT: Class name
// CHECK-CC6-NEXT: Nested name specifier
// CHECK-CC6-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:13:19 %s | FileCheck -check-prefix=CHECK-CC7 %s
// CHECK-CC7: OverloadCandidate:{Text S}{LeftParen (}{Text int}{Comma , }{Text int}{Comma , }{CurrentParameter int}{RightParen )} (1)
// CHECK-CC7: Completion contexts:
// CHECK-CC7-NEXT: Any type
// CHECK-CC7-NEXT: Any value
// CHECK-CC7-NEXT: Enum tag
// CHECK-CC7-NEXT: Union tag
// CHECK-CC7-NEXT: Struct tag
// CHECK-CC7-NEXT: Class name
// CHECK-CC7-NEXT: Nested name specifier
// CHECK-CC7-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:15:21 %s | FileCheck -check-prefix=CHECK-CC8 %s
// CHECK-CC8: Completion contexts:
// CHECK-CC8-NEXT: Any type
// CHECK-CC8-NEXT: Any value
// CHECK-CC8-NEXT: Enum tag
// CHECK-CC8-NEXT: Union tag
// CHECK-CC8-NEXT: Struct tag
// CHECK-CC8-NEXT: Class name
// CHECK-CC8-NEXT: Nested name specifier
// CHECK-CC8-NEXT: Objective-C interface

// RUN: c-index-test -code-completion-at=%s:16:23 %s | FileCheck -check-prefix=CHECK-CC9 %s
// CHECK-CC9: Completion contexts:
// CHECK-CC9-NEXT: Any type
// CHECK-CC9-NEXT: Any value
// CHECK-CC9-NEXT: Enum tag
// CHECK-CC9-NEXT: Union tag
// CHECK-CC9-NEXT: Struct tag
// CHECK-CC9-NEXT: Class name
// CHECK-CC9-NEXT: Nested name specifier
// CHECK-CC9-NEXT: Objective-C interface
