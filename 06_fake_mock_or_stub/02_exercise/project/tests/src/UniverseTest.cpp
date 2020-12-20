#include "Universe.h"
#include "TestIncludes.h"

class Socket {
public:

    virtual ~Socket() = default;

    virtual std::string receive() const = 0;
    virtual void send(const std::string& message) = 0;
};

class Server {
public:

    explicit Server(Socket &socket) : socket(socket) {}

    void run() {

        auto request = socket.receive();

        auto response = "Hello " + request;

        socket.send(response);
    }

private:
    Socket& socket;
};

class SocketMock : public Socket {
public:

    MOCK_CONST_METHOD0(receive, std::string());
    MOCK_METHOD1(send, void(const std::string& message));
};

class SpaceMock : public Space
{
public:
    MOCK_METHOD1(create,void(unsigned int dimensions));
    MOCK_CONST_METHOD0(dimensions,unsigned int());
};
class ObserverMock:public Observer{
public:
    MOCK_METHOD2(remember,void(std::string question,std::string answer));
    MOCK_CONST_METHOD1(answer,std::string(std::string question));
};

class TimeMock:public Time
{
public:
    MOCK_METHOD1(create,void(bool endless));
    MOCK_CONST_METHOD0(now,long long());
    MOCK_METHOD0(flow,void());
};

TEST(Socket, SendAndReceive) {

    StrictMock<SocketMock> socket{};
    Server server{socket};

    EXPECT_CALL(socket, receive()).WillOnce(Return("Tom"));
    EXPECT_CALL(socket, send("Hello Tom"));

    server.run();
}

TEST(Universe, Create)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe u{time,space,observer};
    EXPECT_CALL(time,create(true));
    EXPECT_CALL(space,create(11));
    EXPECT_CALL(space,dimensions()).WillOnce(Return(11));
    EXPECT_CALL(observer,remember("How many dimensions there are?","11"));
    u.create();
}
TEST(Universe,SimulateOne)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};
    Universe u{time,space,observer};

    EXPECT_CALL(time,now()).WillOnce(Return(9300000000)).WillOnce(Return(9300000001));
    EXPECT_CALL(observer,remember("Is there planet Earth?", "Yes!")).Times(1);
    EXPECT_CALL(time,flow()).Times(1);

    u.simulate(9300000001);
}
TEST(Universe,SimulateTwo)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};
    Universe u{time,space,observer};

    EXPECT_CALL(time,now()).WillOnce(Return(9900000000)).WillOnce(Return(9900000001));
    EXPECT_CALL(observer,remember("Does life exist?", "Yes!")).Times(1);
    EXPECT_CALL(time,flow()).Times(1);
    //("Does life exist?", "Yes!");
    u.simulate(9900000001);
}
TEST(Universe,SimulateThree)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};
    Universe u{time,space,observer};

    EXPECT_CALL(time,now()).WillOnce(Return(13800000000)).WillOnce(Return(13800000001));
    EXPECT_CALL(observer,remember("Have People evolved?", "Yes!")).Times(1);
    EXPECT_CALL(time,flow()).Times(1);
    //"Have People evolved?"
    u.simulate(13800000001);
}