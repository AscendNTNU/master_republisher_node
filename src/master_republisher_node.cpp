#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

image_transport::Publisher pub_camComb;
image_transport::Publisher pub_color;
image_transport::Publisher pub_gray;
image_transport::Publisher pub_binary;
image_transport::Publisher pub_red;
image_transport::Publisher pub_green;

void camCombCallback(const sensor_msgs::Image::ConstPtr& msg){
    cv::Mat img = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8)->image;
    sensor_msgs::ImagePtr pub_msg = cv_bridge::CvImage(std_msgs::Header(), "rgb8", img).toImageMsg();
    pub_camComb.publish(pub_msg);
}

void colorCallback(const sensor_msgs::Image::ConstPtr& msg){
    cv::Mat img = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::MONO8)->image;
    sensor_msgs::ImagePtr pub_msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", img).toImageMsg();
    pub_color.publish(pub_msg);
}

void grayCallback(const sensor_msgs::Image::ConstPtr& msg){
    cv::Mat img = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::MONO8)->image;
    sensor_msgs::ImagePtr pub_msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", img).toImageMsg();
    pub_gray.publish(pub_msg);
}

void binaryCallback(const sensor_msgs::Image::ConstPtr& msg){
    cv::Mat img = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::MONO8)->image;
    sensor_msgs::ImagePtr pub_msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", img).toImageMsg();
    pub_binary.publish(pub_msg);
}

void redCallback(const sensor_msgs::Image::ConstPtr& msg){
    cv::Mat img = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::MONO8)->image;
    sensor_msgs::ImagePtr pub_msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", img).toImageMsg();
    pub_red.publish(pub_msg);
}

void greenCallback(const sensor_msgs::Image::ConstPtr& msg){
    cv::Mat img = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::MONO8)->image;
    sensor_msgs::ImagePtr pub_msg = cv_bridge::CvImage(std_msgs::Header(), "mono8", img).toImageMsg();
    pub_green.publish(pub_msg);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "master_republisher_node");
    ros::NodeHandle n;
    image_transport::ImageTransport it(n);

    image_transport::Subscriber sub_camComb = it.subscribe("/camComb_topic", 1, camCombCallback);
    pub_camComb = it.advertise("/republisher/camComb_topic", 1);
    
    image_transport::Subscriber sub_color = it.subscribe("/color_topic", 1, colorCallback);
    pub_color = it.advertise("/republisher/color_topic", 1);

    image_transport::Subscriber sub_gray = it.subscribe("/gray_topic", 1, grayCallback);
    pub_gray = it.advertise("/republisher/gray_topic", 1);

    image_transport::Subscriber sub_binary = it.subscribe("/binary_topic", 1, binaryCallback);
    pub_binary = it.advertise("/republisher/binary_topic", 1);

    image_transport::Subscriber sub_red = it.subscribe("/red_topic", 1, redCallback);
    pub_red = it.advertise("/republisher/red_topic", 1);

    image_transport::Subscriber sub_green = it.subscribe("/green_topic", 1, greenCallback);
    pub_green = it.advertise("/republisher/green_topic", 1);

    ros::spin();

    return 0;
};
