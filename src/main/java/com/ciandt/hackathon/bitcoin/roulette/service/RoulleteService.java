package com.ciandt.hackathon.bitcoin.roulette.service;

import java.util.UUID;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class RoulleteService {

	@RequestMapping(value = "/schedule")
    @ResponseBody
    public String schedule() {
	    
        return "OK";
    }
	
	@RequestMapping(value = "/schedule/check", method = RequestMethod.GET)
    @ResponseBody
    public String checkScheduled() {
        return UUID.randomUUID().toString();
    }
	
	@RequestMapping(value = "/result", method = RequestMethod.PUT)
    @ResponseBody
    public String setResult() {
        return "OK";
    }

    @RequestMapping(value = "/result", method = RequestMethod.GET)
    @ResponseBody
    public String getResult() {
        return "20";
    }
}
