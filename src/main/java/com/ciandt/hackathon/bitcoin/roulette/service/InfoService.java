package com.ciandt.hackathon.bitcoin.roulette.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.env.Environment;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class InfoService {
	@Autowired
	private Environment env;
	
	@Value("${version}")
	private String version;
	
	@Value("${build.date}")
	private String buildDate;
	
	@RequestMapping("/info")
    @ResponseBody
    public String info() {
		version = env.getProperty("version");
		buildDate = env.getProperty("build.date");
        return String.format("Versão da aplicação: %s<br>Data do build: %s", version, buildDate);
    }
}
