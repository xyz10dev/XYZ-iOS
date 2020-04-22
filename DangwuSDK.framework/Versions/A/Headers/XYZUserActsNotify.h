//
//  XYZUserActsNotify.h
//  DangwuSDK
//
//  Created by bai on 2020/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XYZCoordinate : NSObject

@property (nonatomic, assign) double x;
@property (nonatomic, assign) double y;

@end

@interface XYZPoi : NSObject

@property (nonatomic, copy) NSString *poiID;
@property (nonatomic, copy) NSString *poiName;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *floorID;
@property (nonatomic, strong) XYZCoordinate *coordinate;

@end

@interface XYZUserActsNotifyAct : NSObject

@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, copy) NSString *event;
@property (nonatomic, strong) XYZPoi *poi;

@end

@interface XYZUserActsNotify : NSObject

@property (nonatomic, copy) NSString *traceId;
@property (nonatomic, assign) NSTimeInterval timestamp;
@property (nonatomic, strong) NSMutableArray<XYZUserActsNotifyAct *> *actsArray;

@end

NS_ASSUME_NONNULL_END
