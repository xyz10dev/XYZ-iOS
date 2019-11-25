//
//  XYZLocationManager.h
//  XYZ
//
//  Created by mq on 2018/5/14.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "XYZFloorInfo.h"
#import "XYZSiteInfo.h"
#import "XYZLocation.h"

NS_ASSUME_NONNULL_BEGIN

@protocol XYZLocationManagerDelegate;

@interface XYZLocationManager : NSObject

@property (nonatomic, copy) NSString *appKey;
@property (nonatomic, weak) id <XYZLocationManagerDelegate> _Nullable delegate;
@property (nonatomic, nullable, copy) NSString *floorId;
@property (nonatomic, assign) CGPoint coordinate;

/**
 负责管理十域定位服务的单例

 @return XYZLocationManager单例
 */
+ (instancetype _Nonnull)defaultManager;

/**
 开始请求定位
 */
- (void)startUpdatingLocation;

/**
 结束请求定位
 */
- (void)stopUpdatingLocation;

/**
 设备id
 */
+ (NSString *_Nullable)deviceId;

/**
 本次定位的traceid

 @return traceid
 */
- (NSString * _Nullable)currentTraceId;


#pragma mark - 服务器交互

/**
 手动设置场馆

 @param siteId 场馆id
 */
- (void)manualSetSite:(NSString * _Nullable)siteId;


/**
 获取场馆信息

 @param siteId 场馆id
 @param callback 场馆信息回调
 */
- (void)getSiteInfoWithSiteId:(NSString *)siteId callback:(void (^)(XYZSiteInfo *, NSError *))callback;


/**
 手动设置楼层

 @param floorId floorId
 */
- (void)manualSetFloor:(NSString *_Nullable)floorId;


/**
 获取楼层信息

 @param floorId 楼层id
 @param callback 场馆信息回调
 */
- (void)getFloorInfoWithFloorId:(NSString *)floorId callback:(void (^)(XYZFloorInfo *, NSError *))callback;


/**
 自动设置楼层
 */
- (void)autoSetFloor;

@end



#pragma mark - XYZLocationManagerDelegate

@protocol XYZLocationManagerDelegate <NSObject>
@optional
/**
 服务器发送notify类型的数据包时会调用
 
 @param location XYZLocation
 */
- (void)didUpdateLocation:(nonnull XYZLocation *)location;

/**
 服务器发送notify数据包，且返回的楼层和当前楼层不一样时会调用
 
 @param floorId 楼层id
 */
- (void)didEnterFloorId:(nonnull NSString *)floorId;


/**
 error

 @param error error
 */
- (void)didOccurError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
