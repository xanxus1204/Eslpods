//
//  MultipeerHost.h
//  Multipeer0220
//
//  Created by 椛島優 on 2015/02/20.
//  Copyright (c) 2015年 椛島優. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MultipeerConnectivity/MultipeerConnectivity.h>

#define BUF 32768
@protocol MultipeerDataDelegate<NSObject>
-(void)recvDataPacket:(NSData *)data;
@end
@interface MultipeerHost : NSObject<MCSessionDelegate,MCNearbyServiceAdvertiserDelegate,MCNearbyServiceBrowserDelegate>

@property NSString *recvStr;
@property MCPeerID *mPeerID;
@property MCSession *mSession;

@property id<MultipeerDataDelegate> delegate;
-(void)startHost;
-(void)startClient;
-(void)stopHost;
-(void)stopClient;
-(void)sendStr:(NSString *)str;
-(void)sendList:(NSArray *)arr;
-(void)sendData:(NSData *)data withSeconds:(NSInteger)seconds ;
-(BOOL)fileCreate:(NSString *)path andData:(NSData*)data;
-(void)disconnect;
@end
