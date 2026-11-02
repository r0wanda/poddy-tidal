#pragma once
#include "../external/base64.hpp"
#include "../external/uriComponent.hpp"

class TidalMod {
public:
	TidalMod() {
        self.client_id = CLIENT_ID
        self.client_secret = CLIENT_SECRET
	}
void getDeviceAuth(self) {}
	std::string body = "client_id=" + clientId + "&scope=r_usr+w_usr+w_sub";
	std::list<std::string> headers;
	headers.push_back("User-Agent: " + userAgent);
	headers.push_back("Content-Type: application/x-www-form-urlencoded");
	headers.push_back("Content-Length: " + std::to_string(body.length()));
	using namespace curlpp::Options;
	curlpp::Easy req;
	req.setOpt(new HttpHeader(headers));
	req.setOpt(new Encoding("utf8"));
	req.setOpt(new PostFields(body));
	req.setOpt(new PostFieldSize(body.length()));
	req.setOpt(new Url(authUrl + "/device_authorization"));
	std::ostringstream sstrm;
	sstrm << req;

	//std::cout << sstrm.str();
	nlohmann::json res = nlohmann::json::parse(sstrm.str());
	}

    def get_auth(self, device_code: str) -> JSON:
        res = request(
            "POST",
            f"{self.auth_url}/token",
            data={
                "client_id": self.client_id,
                "device_code": device_code,
                "grant_type": "urn:ietf:params:oauth:grant-type:device_code",
                "scope": "r_usr+w_usr+w_sub",
            },
            auth=(self.client_id, self.client_secret),
        )

        json_data = res.json()

        if res.status_code != 200:
            raise AuthClientError(**json_data)

        return json_data

    def refresh_token(self, refresh_token: str) -> JSON:
        res = request(
            "POST",
            f"{self.auth_url}/token",
            data={
                "client_id": self.client_id,
                "refresh_token": refresh_token,
                "grant_type": "refresh_token",
                "scope": "r_usr+w_usr+w_sub",
            },
            auth=(self.client_id, self.client_secret),
        )

        res.raise_for_status()

        return res.json()

    def logout_token(self, access_token: str) -> None:
        res = request(
            "POST",
            "https://api.tidal.com/v1/logout",
            headers={"authorization": f"Bearer {access_token}"},
        )

        res.raise_for_status()
private:
	static void initCreds() {
		authUrl = "https://auth.tidal.com/v1/oauth2";
		constexpr std::string b64 = "NE4zbjZRMXg5NUxMNUs3cDtvS09YZkpXMzcxY1g2eGFaMFB5aGdHTkJkTkxsQlpkNEFLS1lvdWdNamlrPQ==";
		constexpr std::string Base64::Decode(b64);
	}
	static constexpr std::string authUrl;
	static std::string clientId;
	static std::string clientSecret;
};
