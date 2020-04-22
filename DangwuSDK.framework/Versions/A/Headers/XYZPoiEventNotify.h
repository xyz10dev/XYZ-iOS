//
//  XYZPoiEventNotify.h
//  DangwuSDK
//
//  Created by bai on 2019/12/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYZPoiEvent : NSObject <NSSecureCoding>

@property (nonatomic, copy) NSString *poiEventId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) NSTimeInterval arriveTimestamp;
@property (nonatomic, assign) NSTimeInterval leaveTimestamp;


@end


@interface XYZPoiEventNotify : NSObject <NSSecureCoding>

@property (nonatomic, copy) NSArray<XYZPoiEvent *> *poiEventArray;
@property (nonatomic, copy) NSString *traceId;


@end

NS_ASSUME_NONNULL_END
