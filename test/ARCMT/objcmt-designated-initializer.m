// RUN: rm -rf %t
// RUN: %clang_cc1 -objcmt-migrate-designated-init %s -triple x86_64-apple-darwin11 -fobjc-arc -migrate -o %t.remap
// RUN: c-arcmt-test %t.remap | arcmt-test -verify-transformed-files %s.result
// RUN: %clang_cc1 -triple x86_64-apple-darwin11 -fsyntax-only -x objective-c -fobjc-arc %s.result

#define NS_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))

@class NSString;

@interface B1
-(id)init;
@end

@interface S1 : B1
-(id)initWithFoo:(NSString*)foo;
@end

@implementation S1
-(id)initWithFoo:(NSString*)foo
{
  self = [super init];
  if (self) {
  }
  return self;
}
@end

@interface B2
-(id)init NS_DESIGNATED_INITIALIZER;
@end

@interface S2 : B2
-(id)init;
@end

@implementation S2
-(id)init
{
  self = [super init];
  if (self) {
  }
  return self;
}
@end
