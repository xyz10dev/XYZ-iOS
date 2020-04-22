//
//  XYZPoisNotify.h
//  DangwuSDK
//
//  Created by bai on 2019/12/10.
//

#import <Foundation/Foundation.h>
@class PoisNotify_POI;
@class PoisNotify;

NS_ASSUME_NONNULL_BEGIN

@interface XYZPoiCoordinate : NSObject <NSSecureCoding>

@property (nonatomic, assign) double x;
@property (nonatomic, assign) double y;

@end

@interface XYZPoisInfo : NSObject <NSSecureCoding>

@property (nonatomic, copy) NSString *poiID;
@property (nonatomic, copy) NSString *poiName;
@property (nonatomic, assign) double certainty;
@property (nonatomic, copy) NSString *extraID;
@property (nonatomic, copy) NSString *imageURLString;
@property (nonatomic, copy) NSString *address;
@property (nonatomic, copy) NSString *city;
@property (nonatomic, copy) NSArray<NSString *> *regions;
@property (nonatomic, copy) NSArray<NSString *> *categoryNames;
@property (nonatomic, copy) NSArray<NSString *> *categoryIDs;
@property (nonatomic, assign) NSInteger synthesis;
@property (nonatomic, copy) NSString *shopURLString;
@property (nonatomic, strong) XYZPoiCoordinate *coordinate;

- (instancetype)initWithPoi:(PoisNotify_POI *)poi;

@end

@interface XYZPoisNotify : NSObject <NSSecureCoding>

@property (nonatomic, copy) NSArray<XYZPoisInfo *> *pois;
@property (nonatomic, copy) NSString *floorID;
@property (nonatomic, copy) NSString *traceID;
@property (nonatomic, assign) NSTimeInterval timestamp;

- (instancetype)initWithPoiNotify:(PoisNotify *)notify;

@end

NS_ASSUME_NONNULL_END
